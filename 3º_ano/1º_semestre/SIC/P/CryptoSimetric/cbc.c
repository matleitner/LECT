// Helper file for SIC Lab on Symmetric Cryptography

#include <stdint.h>
#include <memory.h>
#include <assert.h>

#include "aes.h"
#include "cbc.h"

void
aes128_cbc_enc( const void * ctx, const uint8_t * iv, const uint8_t * plaintext, const int plain_size, uint8_t * ciphertext )
{
    assert( ctx != 0 && iv != 0 && plaintext != 0 && ciphertext != 0);
// TODO: add your code here
    for(int i = 0; i < plain_size; i+=AES128_BLOCK_SIZE){
    }

// until here
}

void
aes128_cbc_dec( const void * ctx, const uint8_t * iv, const uint8_t * ciphertext, const int cipher_size, uint8_t * plaintext )
{
    assert( ctx != 0 && iv != 0 && plaintext != 0 && ciphertext != 0);
// TODO: add your code here
    
    for(int i = 0; i < cipher_size; i+=AES128_BLOCK_SIZE){
    }
// until here
}
