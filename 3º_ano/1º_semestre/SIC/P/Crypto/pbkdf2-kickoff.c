// Helper file for SIC Lab on Symmetric Cryptography

#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <assert.h>

void
hex_dump( char * text, uint8_t * data, int data_len )
{
    printf( "%s: ", text );

    for(int i = 0; i < data_len; i++) {
        printf( "%02X ", data[i] );
    }
    printf( "\n" );
}

int
main( int argc, char * argv[] )
{
    const int kdf_iter = 100000; // number of iterations to use in PKCS5_PBKDF2_HMAC
    uint8_t salt[SHA256_DIGEST_LENGTH]; // space for a salt that would be randomly generated
    uint8_t kdf_output[SHA256_DIGEST_LENGTH]; // space for the output key
    uint8_t key[16]; // space for an AES key
    uint8_t iv[16]; // space for an AES CBC IV

    if (argc < 2) {
	fprintf( stderr, "Usage: %s password\n", argv[0] );
	return 1;
    }

    // get salt from a good (and fast) source of randomness
    int fd = open( "/dev/urandom", 0 );
    assert( fd != -1 );
    read( fd, salt, sizeof(salt) );
    close ( fd );

    // generate the key
// TODO: add your code here
// until here

    // now we have a key and an IV ...
    memcpy( key, kdf_output,    16 );
    memcpy( iv , kdf_output + 16, 16 );

    // dump the salt
    hex_dump( "Salt", salt, sizeof(salt) );

    // dump the key
    hex_dump( "Key", key, sizeof(key) );

    // dump the IV
    hex_dump( "IV", iv, sizeof(iv) );

    return 0;
}
