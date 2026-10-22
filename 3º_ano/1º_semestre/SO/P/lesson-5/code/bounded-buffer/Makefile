CXX = g++
CXXFLAGS = -Wall -Wextra -Wfatal-errors -ggdb -pthread -I../support/include
LDFLAGS = -pthread -lm

TARGETS = bb-unsafe bb-safe

HEADERS = fifo.h

.PHONY:	all clean cleanall

all: $(TARGETS)

bb-unsafe: main.o fifo-unsafe.o
	$(CXX) -o $@ $^ $(LDFLAGS)

bb-safe: main.o fifo-mon-safe.o
	$(CXX) -o $@ $^ $(LDFLAGS)

*.o:	*.h

clean:
	rm -f *.o Doxyfile.bak

cleanall:	clean
	rm -f $(TARGETS) 
