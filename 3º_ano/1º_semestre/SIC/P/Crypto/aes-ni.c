#include <stdint.h>
#include <memory.h>
#include <wmmintrin.h>
#include <assert.h>

#include "aes.h"

/*
 * AES implemneted with Intel AES-NI instructions
 * Helper file for SIC Lab on Symmetric Cryptography
 * Compile with: -Wall -msse2 -msse -maes
 */

#define AES128_ROUNDS 10

#define AES128_key_exp(k, p) aes128_key_expansion(k, _mm_aeskeygenassist_si128(k, p))

static __m128i
aes128_key_expansion( __m128i key, __m128i keygened )
{
    keygened = _mm_shuffle_epi32( keygened, _MM_SHUFFLE( 3,3,3,3 ) );
    key = _mm_xor_si128( key, _mm_slli_si128( key, 4 ) );
    key = _mm_xor_si128( key, _mm_slli_si128( key, 4 ) );
    key = _mm_xor_si128( key, _mm_slli_si128( key, 4 ) );
    return _mm_xor_si128( key, keygened );
}

void *
aes128_init_context( const uint8_t * key )
{
    __m128i * round_keys = malloc( (2 + 2 * AES128_ROUNDS) * sizeof(__m128i) );

    round_keys[ 0] = _mm_loadu_si128( (const __m128i*) key );
    round_keys[ 1] = AES128_key_exp( round_keys[0], 0x01 );
    round_keys[ 2] = AES128_key_exp( round_keys[1], 0x02 );
    round_keys[ 3] = AES128_key_exp( round_keys[2], 0x04 );
    round_keys[ 4] = AES128_key_exp( round_keys[3], 0x08 );
    round_keys[ 5] = AES128_key_exp( round_keys[4], 0x10 );
    round_keys[ 6] = AES128_key_exp( round_keys[5], 0x20 );
    round_keys[ 7] = AES128_key_exp( round_keys[6], 0x40 );
    round_keys[ 8] = AES128_key_exp( round_keys[7], 0x80 );
    round_keys[ 9] = AES128_key_exp( round_keys[8], 0x1B );
    round_keys[10] = AES128_key_exp( round_keys[9], 0x36 );

    // Decryption round keys are different and will be stored in the upper part of the round keys' array
    __m128i * dec_round_keys = round_keys + AES128_ROUNDS + 1;

    dec_round_keys[10] = round_keys[10];
    dec_round_keys[ 9] = _mm_aesimc_si128( round_keys[9] );
    dec_round_keys[ 8] = _mm_aesimc_si128( round_keys[8] );
    dec_round_keys[ 7] = _mm_aesimc_si128( round_keys[7] );
    dec_round_keys[ 6] = _mm_aesimc_si128( round_keys[6] );
    dec_round_keys[ 5] = _mm_aesimc_si128( round_keys[5] );
    dec_round_keys[ 4] = _mm_aesimc_si128( round_keys[4] );
    dec_round_keys[ 3] = _mm_aesimc_si128( round_keys[3] );
    dec_round_keys[ 2] = _mm_aesimc_si128( round_keys[2] );
    dec_round_keys[ 1] = _mm_aesimc_si128( round_keys[1] );
    dec_round_keys[ 0] = round_keys[ 0];

    return round_keys;
}

void
aes128_free_context( void ** ctx )
{
    assert( ctx != 0);

    free( *ctx );
    *ctx = 0;
}

void
aes128_block_enc( const void * ctx, const uint8_t * plaintext, uint8_t * ciphertext )
{
    assert( ctx != 0 && plaintext != 0 && ciphertext != 0);

    const __m128i * round_keys = ctx;
    __m128i m = _mm_loadu_si128( (const __m128i *) plaintext );

    m = _mm_xor_si128       ( m, round_keys[ 0] );
    m = _mm_aesenc_si128    ( m, round_keys[ 1] );
    m = _mm_aesenc_si128    ( m, round_keys[ 2] );
    m = _mm_aesenc_si128    ( m, round_keys[ 3] );
    m = _mm_aesenc_si128    ( m, round_keys[ 4] );
    m = _mm_aesenc_si128    ( m, round_keys[ 5] );
    m = _mm_aesenc_si128    ( m, round_keys[ 6] );
    m = _mm_aesenc_si128    ( m, round_keys[ 7] );
    m = _mm_aesenc_si128    ( m, round_keys[ 8] );
    m = _mm_aesenc_si128    ( m, round_keys[ 9] );
    m = _mm_aesenclast_si128( m, round_keys[10] );

    _mm_storeu_si128( (__m128i *) ciphertext, m );
}

void
aes128_block_dec( const void * ctx, const uint8_t * ciphertext, uint8_t * plaintext )
{
    assert( ctx != 0 && plaintext != 0 && ciphertext != 0);

    const __m128i * round_keys = ctx;
    __m128i m = _mm_loadu_si128( (const __m128i *) ciphertext );

    // Decryption round keys are stored in the upper part of the round keys' array
    round_keys += AES128_ROUNDS + 1;

    m = _mm_xor_si128       ( m, round_keys[10] );
    m = _mm_aesdec_si128    ( m, round_keys[ 9] );
    m = _mm_aesdec_si128    ( m, round_keys[ 8] );
    m = _mm_aesdec_si128    ( m, round_keys[ 7] );
    m = _mm_aesdec_si128    ( m, round_keys[ 6] );
    m = _mm_aesdec_si128    ( m, round_keys[ 5] );
    m = _mm_aesdec_si128    ( m, round_keys[ 4] );
    m = _mm_aesdec_si128    ( m, round_keys[ 3] );
    m = _mm_aesdec_si128    ( m, round_keys[ 2] );
    m = _mm_aesdec_si128    ( m, round_keys[ 1] );
    m = _mm_aesdeclast_si128( m, round_keys[ 0] );
    
    _mm_storeu_si128( (__m128i *) plaintext, m );
}
