CFLAGS := -Wall -g

all: avalanche-analysis

avalanche-analysis: avalanche-analysis.o
	$(CC) -g -o $@ $^ -lcrypto

clean:
	rm *.o
	rm avalanche-analysis
