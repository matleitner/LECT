#include <stdio.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <assert.h>

#include "aes.h"

/*
 * AES implemneted with Openssl library functions
 * Helper file for SIC Lab on Symmetric Cryptography
 */

typedef struct {
    EVP_CIPHER_CTX * enc;
    EVP_CIPHER_CTX * dec;
} ctx_t;

void * 
aes128_init_context( const uint8_t * key )
{
    ctx_t * ctx = malloc( sizeof(ctx_t) );

    ctx->enc = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex ( ctx->enc, EVP_aes_128_ecb(), NULL, key, NULL );
    EVP_CIPHER_CTX_set_padding( ctx->enc, 0 );

    ctx->dec = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex ( ctx->dec, EVP_aes_128_ecb(), NULL, key, NULL );
    EVP_CIPHER_CTX_set_padding( ctx->dec, 0 );

    return ctx;
}

void
aes128_free_context( void ** _ctx )
{
    assert( *_ctx != 0 );

    ctx_t * ctx = *((ctx_t **) _ctx);

    EVP_CIPHER_CTX_free( ctx->enc );
    EVP_CIPHER_CTX_free( ctx->dec );
    free( ctx );

    *_ctx = 0;
}

void
aes128_block_enc( const void * ctx, const uint8_t * plaintext, uint8_t * ciphertext )
{
    int length = 0;

    assert( ctx != 0 && plaintext != 0 && ciphertext != 0);

    EVP_EncryptUpdate( ((ctx_t *) ctx)->enc, ciphertext, &length, plaintext, AES128_BLOCK_SIZE );

    assert( length == AES128_BLOCK_SIZE );
}


void
aes128_block_dec( const void * ctx, const uint8_t * ciphertext, uint8_t * plaintext )
{
    int length = AES128_BLOCK_SIZE;

    assert( ctx != 0 && plaintext != 0 && ciphertext != 0);

    EVP_DecryptUpdate( ((ctx_t *) ctx)->dec, plaintext, &length, ciphertext, AES128_BLOCK_SIZE );

    assert( length == AES128_BLOCK_SIZE );
}
