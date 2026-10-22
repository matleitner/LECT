/*
* Helper file for SIC Lab on Cryptograph Hashing
* Compile this file with:
* gcc -O2 -Wall avalanche-analysis.c -o avalanche-analysis -lcrypto
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>

#include <openssl/types.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#ifndef MAX
#define MAX(x,y) (x > y ? x : y)
#endif

// this is big enough for all our targets: sha256 and md5
#define HASH_OUTPUT_MAX_BYTES   MAX( MD5_DIGEST_LENGTH,SHA256_DIGEST_LENGTH )
#define HASH_OUTPUT_MAX_BITS	(8 * HASH_OUTPUT_MAX_BYTES)
#define HASH_OUTPUT_BLOCK_SIZE	HASH_OUTPUT_MAX_BYTES

/*
* TODO
* you may want to give more options and details here!
*/
int
usage( const char * app ) {
    fprintf( stderr, "Usage:\n\t%s  M  N [digest function]\n\n"
                     "\tM: the size in bytes of the initial source message\n"
                     "\tN: the number of one-bit altered messages\n"
                     "\t[MD5 | SHA-256]: the digest function to study (SHA-1 by default)\n", app );
    return -2;
}

static int ones[16] = {
    0, 1, 1, 2, // 0 to 3
    1, 2, 2, 3, // 4 to 7
    1, 2, 2, 3, // 8 to 11
    2, 3, 3, 4  // 12 to 15
};

// Counts 1's in a byte
int
count_1s( uint8_t c )
{
    return ones[c & 0xF] + ones[c >> 4];
}

// Returns the number of bits at 1 within the first `size` bytes
int
count_diff_bits( const uint8_t *h1, const uint8_t *h2, const uint32_t size )
{
    int n = 0;

    for (int i = 0; i < size; i++) {
        n += count_1s( h1[i] ^ h2[i] );
    }

    assert( n <= 8 * size );

    return n;
}

/*
* Copies `source` to `working_buf` and changes a bit on `working_buf`
* also writes the index of the bit changed to `track_mods`
*/
void
change_me_a_bit( const uint8_t *source, const uint32_t source_size,
	          uint8_t *track_mods, uint8_t *working_buf )
{
    memcpy( working_buf, source, source_size );

    uint32_t bit_idx = rand() % source_size * 8; // the (random) bit index
    uint32_t byte_idx = bit_idx / 8;
    uint32_t bit_offset = bit_idx % 8;
    uint8_t bit_mask = 1 << bit_offset;

    uint32_t try = 0;

    while (track_mods[byte_idx] & bit_mask) { // Deja vu bit?
	try++;

        assert( try < source_size * 8 ); // if all bits were already modified

	bit_idx = (bit_idx + 1) % (source_size * 8); // Try next bit
	byte_idx = bit_idx / 8;
	bit_offset = bit_idx % 8;
	bit_mask = 1 << bit_offset;
    }

    working_buf[byte_idx] ^= bit_mask; // change the bit
    track_mods[byte_idx] |= bit_mask; // stores the action

    assert( count_diff_bits( source, working_buf, source_size ) == 1);
}

//TODO: Similar to change_me_a_bit but a byte!
void
change_me_a_byte( const uint8_t *source, const uint32_t source_size,
		   uint8_t *track_mods, uint8_t *working_buf )
{
        memcpy( working_buf, source, source_size );

    uint32_t byte_idx = rand() % source_size; // the (random) bit index

    uint32_t try = 0;

    while (track_mods[byte_idx] != 0 ) { // Deja vu bit?
	try++;

        assert( try < source_size ); // if all bits were already modified

	byte_idx = (byte_idx + 1) % (source_size ); // Try next bit
    }

    working_buf[byte_idx] ^= 0xFF; // change the bit
    track_mods[byte_idx] |= 1; // stores the action

    assert( count_diff_bits( source, working_buf, source_size ) == 8);

}

// Produces sha256 from `data` with `data_size` bytes and writes the output to `output_hash`
void
sha256( const uint8_t *data, const uint32_t data_size, uint8_t *output_hash )
{
    EVP_MD_CTX * ctx = EVP_MD_CTX_new(); // The generic hashing context

    EVP_DigestInit( ctx, EVP_sha256() ); // Context initialization

    // Process the entire data and Compute the the final hash value
    EVP_DigestUpdate( ctx, data, data_size );
    EVP_DigestFinal( ctx, output_hash, 0 );

    EVP_MD_CTX_free( ctx );
}

// Produces md5 from `data` with `data_size` bytes and writes the output to `output_hash`
void
md5( const uint8_t *data, const uint32_t data_size, uint8_t *output_hash )
{
    EVP_MD_CTX * ctx = EVP_MD_CTX_new(); // The generic hashing context

    EVP_DigestInit( ctx, EVP_md5() ); // Context initialization

    // Process the entire data and Compute the the final hash value
    EVP_DigestUpdate( ctx, data, data_size );
    EVP_DigestFinal( ctx, output_hash, 0 );

    EVP_MD_CTX_free( ctx );
}

int
main( int argc, char *argv[] )
{
    const EVP_MD * func_template = EVP_sha1();

    // we want 2 arguments
    if (argc < 3) {
        return usage( argv[0] );
    }

    // get the numbers
    uint32_t source_size;
    uint32_t n_variations;

    assert( sscanf( argv[1], "%d", &source_size ) );
    assert( sscanf( argv[2], "%d", &n_variations ) );
    if (argc >= 4) {
	if (strcmp( argv[3], "MD5" ) == 0) {
	    func_template = EVP_md5();
	}
	else if (strcmp( argv[3], "SHA-256" ) == 0) {
	    func_template = EVP_sha256();
	}
	else {
	    return usage( argv[0] );
	}
    }

    fprintf( stderr,"Working with M=%d and N=%d...\n", source_size, n_variations );

    assert( n_variations <= source_size * 8 );

    // get some space for histogram and fill it with zeros
    uint32_t histogram[HASH_OUTPUT_MAX_BITS + 1];
    memset( histogram, 0, sizeof(histogram) );

    // space for source
    uint8_t * source = malloc( source_size );
    assert( source != 0 );

    // space for 1bit variation
    uint8_t * bit_mod = malloc( source_size );
    assert( bit_mod != 0 );

    /*
    * Used to avoid repetition on the 1bit modification
    * calloc zeros it
    */
    uint8_t * track_mods = calloc( source_size, 1 );

    // Fill source with random data fickedup from /dev/urandom file
    int fd = open( "/dev/urandom", 0 );
    read( fd, source, source_size );
    close ( fd );

    uint8_t source_hash[HASH_OUTPUT_BLOCK_SIZE];
    uint8_t bit_mod_hash[HASH_OUTPUT_BLOCK_SIZE];

    unsigned int size_of_hash = EVP_MD_get_size( func_template );

    EVP_Digest( source, source_size, source_hash, &size_of_hash, func_template, 0 );

    // TODO: add your code here
    for ( int i = 0; i < n_variations; i++){
    // until here
	change_me_a_bit( source, source_size, track_mods, bit_mod );
	EVP_Digest( bit_mod, source_size, bit_mod_hash, &size_of_hash, func_template, 0 );

	int n = count_diff_bits( source_hash, bit_mod_hash, size_of_hash );
	histogram[n]++;
    // TODO: add your code here
    }
    // until here

    // make sure we have used N different 1-bit modifications
    uint8_t * zeros = calloc( source_size, 1 );
    assert( count_diff_bits( track_mods, zeros, source_size ) == n_variations );

    printf( "The results are...\n" );
    for (int i = 0;i <= size_of_hash * 8; i++) {
        printf( "%3d %d\n", i, histogram[i] );
    }

    // done
    free( source );
    free( bit_mod );
    free( track_mods );

    return 0;
}
