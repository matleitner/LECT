#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include <arpa/inet.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <assert.h>

#include "aes.h"
#include "ecb.h"
#include "cbc.h"

int
exact_read( int fd, uint8_t * buffer, int len )
{
    int last;
    int effective = 0;

    while (len != 0) {
	last = read( fd, buffer, len );

	if (last <= 0) return effective;

	buffer += last;
	effective = last;
	len -= last;
    }

    return effective;
}

void
padded_cipher( uint8_t * key,
	    void (*func)(const void*,const uint8_t*,const int,uint8_t*),
	    void (*iv_func)(const void*,const uint8_t*,const uint8_t*,const int,uint8_t*) )
{
    uint8_t buffer[16 * 1024];
    uint8_t ciphertext[16 * 1024];
    void * ctx = aes128_init_context( key );
    int len = 0;
    uint8_t iv[16];

    if (iv_func) memcpy( iv, key + 16, sizeof(iv) );

    for (;;) {
	len = exact_read( 0, buffer, sizeof(buffer) );

	if (len <= 0) {
	    len = 0;
	    break;
	}

	if (len != sizeof(buffer) ) {
	    break;
	}

	if (iv_func) {
	    (*iv_func)( ctx, iv, buffer, sizeof(buffer), ciphertext );
	    memcpy( iv, ciphertext + sizeof(ciphertext) - sizeof(iv), sizeof(iv) );
	}
	else {
	    (*func)( ctx, buffer, sizeof(buffer), ciphertext );
	}

	write( 1, ciphertext, sizeof(ciphertext) );
    }

    // padding
    
    uint8_t pad_len = 16 - (len % 16);

    for (int i = 0; i < pad_len; i++) {
	buffer[len + i] = pad_len;
    }

    if (iv_func) {
	(*iv_func)( ctx, iv, buffer, len + pad_len, ciphertext );
    }
    else {
	(*func)( ctx, buffer, len + pad_len, ciphertext );
    }
    
    write( 1, ciphertext, len + pad_len );

    aes128_free_context( &ctx );
}

void
unpadded_decipher( uint8_t * key,
	    void (*func)(const void*,const uint8_t*,const int,uint8_t*),
	    void (*iv_func)(const void*,const uint8_t*,const uint8_t*,const int,uint8_t*) )
{
    uint8_t buffer[16 * 1024];
    uint8_t plaintext[16 * 1024];
    void * ctx = aes128_init_context( key );
    int len;
    uint8_t iv[16];
    uint8_t last_block[16];
    int use_last_block = 0;

    if (iv_func) memcpy( iv, key + 16, sizeof(iv) );

    for (;;) {
	len = exact_read( 0, buffer, sizeof(buffer) );

	if (len <= 0) {
	    break;
	}

	if (len % 16) { // Input not block aligned
	    fprintf( stderr, "Input data is not suitable, it is not block aligned\n" );
	    exit( 1 );
	}

	if (iv_func) {
	    (*iv_func)( ctx, iv, buffer, len, plaintext );
	    memcpy( iv, buffer + len - sizeof(iv), sizeof(iv) );
	}
	else {
	    (*func)( ctx, buffer, len, plaintext );
	}

	if (use_last_block) {
	    write( 1, last_block, sizeof(last_block) );
	}
	else {
	    use_last_block = 1;
	}
	write( 1, plaintext, len - sizeof(last_block) );
	memcpy( last_block, plaintext + len - sizeof(last_block), sizeof(last_block) );
    }

    // unpadding
    
    uint8_t pad_len = last_block[sizeof(last_block) - 1];

    if (pad_len < 1 || pad_len > sizeof(last_block)) {
	fprintf( stderr, "Input data is not suitable, it lacks a proper padding\n" );
	exit( 2 );
    }


    for (int i = 1; i < pad_len; i++) {
	if (last_block[sizeof(last_block) - 1 - i] != pad_len) {
	    fprintf( stderr, "Input data is not suitable, it lacks a proper padding\n" );
	    exit( 2 );
	}
    }

    write( 1, last_block, sizeof(last_block) - pad_len );

    aes128_free_context( &ctx );
}

void
enc_ecb( uint8_t * key )
{
    padded_cipher( key, aes128_ecb_enc, 0 );
}

void
dec_ecb( uint8_t * key )
{
    unpadded_decipher( key, aes128_ecb_dec, 0 );
}

void
enc_cbc( uint8_t * key )
{
    padded_cipher( key, 0, aes128_cbc_enc );
}

void
dec_cbc( uint8_t * key )
{
    unpadded_decipher( key, 0, aes128_cbc_dec );
}

void
usage( char * app )
{
    fprintf( stderr, "Usage: %s [E|D] [ECB|CBC] password", app );
    exit( 1 );
}

typedef struct {
    uint8_t salt[16];
    uint32_t iterations; // NET format
} key_params_t;

void
gen_params( key_params_t * params )
{
    int fd = open( "/dev/urandom", 0 );

    assert( fd != -1 );
    exact_read( fd, params->salt, sizeof(params->salt) );
    close ( fd );

    params->iterations = 100000;
}

void
write_params( int fd, key_params_t * params )
{
    key_params_t copy = *params;
    copy.iterations = htonl( params->iterations );

    write( fd, &copy, sizeof(copy) );
}

void
read_params( int fd, key_params_t * params )
{
    int len;

    len = exact_read( fd, (uint8_t  *) params, sizeof(key_params_t) );
    if (len != sizeof(key_params_t)) {
	fprintf( stderr, "Input data is not suitable, it lacks a proper encryption header\n" );
	exit( 2 );
    }
    params->iterations = ntohl( params->iterations );
}

void
gen_key( char * password, key_params_t * params, uint8_t * key, int key_len )
{
    PKCS5_PBKDF2_HMAC( password, strlen( password ),
			params->salt, sizeof(params->salt),
			params->iterations,
			EVP_sha256(),
			key_len, key );
}

int
main( int argc, char * argv[] )
{
    if (argc != 4) {
	usage( argv[0] );
    }

    if (strcmp( argv[1], "E" ) != 0 && strcmp( argv[1], "D" ) != 0) {
	usage( argv[0] );
    }

    if (strcmp( argv[2], "ECB" ) != 0 && strcmp( argv[2], "CBC" ) != 0) {
	usage( argv[0] );
    }

    key_params_t params;

    if (strcmp( argv[1], "E" ) == 0) {
	gen_params( &params );
	write_params( 1, &params );

	if (strcmp( argv[2], "ECB" ) == 0) {
	    uint8_t key[16];

	    gen_key( argv[3], &params, key, sizeof(key) );
	    enc_ecb( key );
	}
	else { // CBC
	    uint8_t key[32]; // Key & IV

	    gen_key( argv[3], &params, key, sizeof(key) );
	    enc_cbc( key );
	}
    }
    else { // Decrypt
	read_params( 0, &params );

	if (strcmp( argv[2], "ECB" ) == 0) {
	    uint8_t key[16];

	    gen_key( argv[3], &params, key, sizeof(key) );
	    dec_ecb( key );
	}
	else {
	    uint8_t key[32]; // Key & IV

	    gen_key( argv[3], &params, key, sizeof(key) );
	    dec_cbc( key );
	}
    }
}
