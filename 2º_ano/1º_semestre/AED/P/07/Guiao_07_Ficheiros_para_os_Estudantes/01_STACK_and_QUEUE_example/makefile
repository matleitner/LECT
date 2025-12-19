CFLAGS += -g -Wall -Wextra

TARGETS = 01_example

all: $(TARGETS)

IntegersStack.o: IntegersStack.c IntegersStack.h

IntegersQueue.o: IntegersQueue.c IntegersQueue.h

01_example.o: 01_example.c IntegersStack.h IntegersQueue.h

01_example: 01_example.o IntegersStack.o IntegersQueue.o


clean:
	rm -f *.o
	rm -f $(TARGETS)
