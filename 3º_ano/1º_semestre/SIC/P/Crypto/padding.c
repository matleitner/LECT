// Helper file for SIC Lab on Symmetric Cryptography

#include <stdint.h>
#include <assert.h>

#include "aes.h"
#include "padding.h"

// Adds PKCS#7 padding and returns the new plaintext length

int
add_padding( uint8_t * plain, const int plain_size )
{
    assert( plain != 0 );
// TODO: add your code here
// until here
}

/*
 * Checks PKCS#7 padding and returns the original plaintext length (w/o padding)
 * If an error is found in the padding, it returns -1.
*/

int
rm_padding( uint8_t * padded, const int full_size )
{
    assert( padded != 0 );
// TODO: add your code here
// until here
}
