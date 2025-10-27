# To compile all programs, run:
#   make
# 
# JMR 2021, JMadeira 2023


# Options for the C compiler. 
CFLAGS += -g -Wall -Wextra

TARGETS = Tests

all: $(TARGETS)

Date.o: Date.c Date.h

Person.o: Person.c Person.h Date.h

Tests.o: Tests.c Date.h Person.h

Tests: Tests.o Date.o Person.o

clean:
	rm -f *.o
	rm -f $(TARGETS)
