/*
 * Generate an RSA key pair using the OpenSSL EVP interface.
 *
 * Public exponent:
 *
 *     e = 2^16 + 1 = 65537
 *
 * Output:
 *   - Private key: PEM, PKCS#8 format
 *   - Public key:  PEM, SubjectPublicKeyInfo format
 *
 * Compile:
 *   cc -Wall -Wextra -O2 gen_rsa_evp.c -o gen_rsa_evp $(pkg-config --cflags --libs openssl)
 *
 * Example:
 *   ./gen_rsa_evp 3072 private_key.pem public_key.pem
 */

#include <stdio.h>
#include <stdlib.h>

#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/core_names.h>
#include <openssl/param_build.h>

/*
 * Set e (public exponent) and bits (modulus length) parameters
 */

static OSSL_PARAM *
set_rsa_params( BIGNUM * e, int bits )
{
    OSSL_PARAM_BLD * param_bld = OSSL_PARAM_BLD_new();
    OSSL_PARAM * params = NULL;

    if (param_bld == NULL) {
        fprintf( stderr, "OSSL_PARAM_BLD_new failed\n" );
        return params;
    }

    /*
     * RSA key generation parameters:
     *
     *   OSSL_PKEY_PARAM_BITS  -> modulus size in bits
     *   OSSL_PKEY_PARAM_RSA_E -> public exponent
     */

    if (OSSL_PARAM_BLD_push_uint(param_bld, OSSL_PKEY_PARAM_BITS, bits) != 1) {
        fprintf( stderr, "OSSL_PARAM_BLD_push_uint(bits) failed\n" );
        return params;
    }

    if (OSSL_PARAM_BLD_push_BN(param_bld, OSSL_PKEY_PARAM_RSA_E, e) != 1) {
        fprintf( stderr, "OSSL_PARAM_BLD_push_BN(e) failed\n" );
        return params;
    }

    params = OSSL_PARAM_BLD_to_param( param_bld );
    if (params == NULL) {
        fprintf(stderr, "OSSL_PARAM_BLD_to_param failed\n");
    }

    OSSL_PARAM_BLD_free( param_bld );

    return params;
}

static int
generate_rsa_key( EVP_PKEY ** out_key, int bits )
{
    EVP_PKEY_CTX *ctx = NULL;
    BIGNUM * e = NULL;
    OSSL_PARAM * params = NULL;
    int ok = 0;

    if (out_key == NULL || bits < 1024) {
        fprintf( stderr, "Invalid arguments: key size should be at least 1024 bits\n" );
        return 0;
    }

    *out_key = NULL;

    ctx = EVP_PKEY_CTX_new_id( EVP_PKEY_RSA, NULL );
    if (ctx == NULL) {
        fprintf( stderr, "EVP_PKEY_CTX_new_id failed\n" );
        goto cleanup;
    }

    if (EVP_PKEY_keygen_init( ctx ) <= 0) {
        fprintf( stderr, "EVP_PKEY_keygen_init failed\n" );
        goto cleanup;
    }

    e = BN_new();
    if (e == NULL) {
        fprintf( stderr, "BN_new failed\n" );
        goto cleanup;
    }

    if (BN_set_word( e, 65537UL ) != 1) {
        fprintf( stderr, "BN_set_word failed\n" );
        goto cleanup;
    }

    params = set_rsa_params( e, bits );

    if (EVP_PKEY_CTX_set_params( ctx, params ) <= 0) {
        fprintf( stderr, "EVP_PKEY_CTX_set_params failed\n" );
        goto cleanup;
    }

    if (EVP_PKEY_keygen( ctx, out_key ) <= 0) {
        fprintf(stderr, "EVP_PKEY_keygen failed\n");
        goto cleanup;
    }

    ok = 1;

cleanup:
    if (!ok) {
        ERR_print_errors_fp( stderr );
    }

    EVP_PKEY_CTX_free( ctx );
    BN_free( e );

    return ok;
}

static int
write_PEM_private_key( const char *filename, EVP_PKEY *pkey )
{
    FILE *fp = NULL;
    int ok = 0;

    if (filename == NULL || pkey == NULL) {
        return 0;
    }

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror( "fopen private key" );
        return 0;
    }

    /*
     * This writes an unencrypted private key in PEM format.
     *
     * To encrypt it, replace NULL with a cipher such as EVP_aes_256_cbc()
     * and provide a passphrase.
     */
    if (PEM_write_PrivateKey( fp, pkey, NULL, NULL, 0, NULL, NULL) != 1 ) {
        fprintf( stderr, "PEM_write_PrivateKey failed\n" );
        ERR_print_errors_fp( stderr );
        goto cleanup;
    }

    ok = 1;

cleanup:
    fclose( fp );
    return ok;
}

static int
write_PEM_public_key( const char *filename, EVP_PKEY *pkey )
{
    FILE *fp = NULL;
    int ok = 0;

    if (filename == NULL || pkey == NULL) {
        return 0;
    }

    fp = fopen( filename, "wb" );
    if (fp == NULL) {
        perror( "fopen public key" );
        return 0;
    }

    /*
     * PEM_write_PUBKEY writes the public key in SubjectPublicKeyInfo format:
     *
     *     -----BEGIN PUBLIC KEY-----
     *
     * This is usually preferred over the older RSA-specific public key format.
     */
    if (PEM_write_PUBKEY( fp, pkey ) != 1) {
        fprintf( stderr, "PEM_write_PUBKEY failed\n" );
        ERR_print_errors_fp( stderr );
        goto cleanup;
    }

    ok = 1;

cleanup:
    fclose( fp );
    return ok;
}

int main( int argc, char **argv )
{
    int bits;
    EVP_PKEY *pkey = NULL;

    if (argc != 4) {
        fprintf( stderr, "Usage: %s <bits> <private-key.pem> <public-key.pem>\n", argv[0] );
        fprintf( stderr, "Example: %s 3072 private_key.pem public_key.pem\n", argv[0] );
        return -1;
    }

    bits = atoi( argv[1] );
    if (bits < 1024) {
        fprintf( stderr, "Invalid key size: use at least 1024 bits\n" );
        return -1;
    }

    if (!generate_rsa_key( &pkey, bits) ) {
        fprintf( stderr, "RSA key generation failed\n" );
        return -1;
    }

    if (!write_PEM_private_key( argv[2], pkey )) {
        fprintf( stderr, "Failed to write private key\n" );
        EVP_PKEY_free( pkey );
        return -1;
    }

    if (!write_PEM_public_key( argv[3], pkey )) {
        fprintf( stderr, "Failed to write public key\n" );
        EVP_PKEY_free( pkey );
        return -1;
    }

    EVP_PKEY_free( pkey );

    printf( "RSA key pair generated successfully.\n" );
    printf( "Private key: %s\n", argv[2] );
    printf( "Public key:  %s\n", argv[3] );

    return 0;
}
