#define AES128_BLOCK_SIZE 16

void * aes128_init_context( const uint8_t * key );
void aes128_free_context( void ** ctx );
void aes128_block_enc( const void * ctx, const uint8_t * plaintext, uint8_t * ciphertext );
void aes128_block_dec( const void * ctx, const uint8_t * ciphertext, uint8_t * plaintext );
