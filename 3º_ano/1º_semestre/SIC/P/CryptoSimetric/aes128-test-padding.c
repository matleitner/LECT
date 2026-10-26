// Helper file for SIC Lab on Symmetric Cryptography

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#include "aes.h"
#include "padding.h"

void
aes128_block_test_padding()
{
    const uint8_t tv_key[]    = {0xED, 0xFD, 0xB2, 0x57, 0xCB, 0x37, 0xCD, 0xF1, 0x82, 0xC5, 0x45, 0x5B, 0x0C, 0x0E, 0xFE, 0xBB};
    const uint8_t tv_plain[]  = {0x00};
    const uint8_t tv_cipher[] = {0x1C, 0x8C, 0xF2, 0x3A, 0x59, 0x99, 0xDC, 0x4B, 0x8A, 0xE7, 0xB5, 0x2F, 0x8C, 0x47, 0x12, 0x25};

    // space for outputs
    uint8_t computed_cipher[sizeof(tv_cipher)];
    uint8_t computed_plain[sizeof(tv_cipher)];

    // allocate an extra block for the plaintext to assume the worst case for padding
    uint8_t * padding_plain = malloc( sizeof(tv_plain) + AES128_BLOCK_SIZE );

    memcpy( padding_plain, tv_plain, sizeof(tv_plain) );
    assert( add_padding( padding_plain, sizeof(tv_plain) ) == AES128_BLOCK_SIZE );

    void * ctx = aes128_init_context( tv_key );
    aes128_block_enc( ctx, padding_plain, computed_cipher );
    aes128_block_dec( ctx, computed_cipher, computed_plain );

    // tests
    assert( rm_padding( computed_plain, AES128_BLOCK_SIZE ) == sizeof(tv_plain) );
    assert( memcmp( tv_cipher, computed_cipher, AES128_BLOCK_SIZE ) == 0 );
    assert( memcmp( tv_plain, computed_plain, sizeof(tv_plain) ) == 0 );

    // done
    free( padding_plain );
    aes128_free_context( &ctx );
}

void
aes128_ecb_test_padding()
{
// TODO: add your code here
// until here
}

void
aes128_cbc_test_padding()
{
// TODO: add your code here
// until here
}

int
main()
{
    printf( "Test padding & unpadding with AES simple block encryption/decryption\n" );
    aes128_block_test_padding ();

    printf( "Test padding & unpadding with AES ECB encryption/decryption\n" );
    aes128_ecb_test_padding ();

    printf( "Test padding & unpadding with AES CBC encryption/decryption\n" );
    aes128_cbc_test_padding ();

    return 0;
}
