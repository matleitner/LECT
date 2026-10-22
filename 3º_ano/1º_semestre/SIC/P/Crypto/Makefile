CFLAGS := -Wall -g
CFLAGS_AES_NI := -msse2 -msse -maes

all: aes128-test-modes aes128-test-modes-ni aes128-test-padding pbkdf2-kickoff file_ed file_ed_ni

aes-ni.o: aes-ni.c
	$(CC) $(CFLAGS) $(CFLAGS_AES_NI) -o $@ -c $^

aes128-test-modes: aes128-test-modes.o ecb.o cbc.o aes-sw.o
	$(CC) -g -o $@  $^ -lcrypto

aes128-test-modes-ni: aes128-test-modes.o ecb.o cbc.o aes-ni.o
	$(CC) -g -o $@  $^

aes128-test-padding: aes128-test-padding.o padding.o aes-sw.o 
	$(CC) -g -o $@  $^ -lcrypto

pbkdf2-kickoff: pbkdf2-kickoff.o
	$(CC) -g -o $@  $^ -lcrypto

file_ed: file_ed.o ecb.o cbc.o aes-sw.o
	$(CC) -g -o $@  $^ -lcrypto

file_ed_ni: file_ed.o ecb.o cbc.o aes-ni.o
	$(CC) -g -o $@  $^ -lcrypto

clean:
	-rm *.o
	-rm aes128-test-modes aes128-test-modes-ni aes128-test-padding pbkdf2-kickoff
