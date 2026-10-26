CFLAGS := -Wall -Wextra -g 
OPENSSL_LIBS := $(pkg-config --cflags --libs openssl)

all: gen_rsa_key

%.o: %.c
	cc -c -o $@ $(CFLAGS) $*.c $(OPENSSL_LIBS)

gen_rsa_key: gen_rsa_key.o
	cc  -o $@ $^ -lcrypto
