CXX = g++
CXXFLAGS = -Wall -Wextra -Wfatal-errors -ggdb -pthread -I../support/include
LDFLAGS = -pthread -lm

TARGETS = bb-unsafe bb-sem-safe

HEADERS = fifo.h

.PHONY:	all clean cleanall

all: $(TARGETS)

bb-unsafe:	fifo-unsafe.o main.o
	g++ -o $@ $^ $(LDFLAGS)

bb-sem-safe:	fifo-sem-safe.o main.o
	g++ -o $@ $^ $(LDFLAGS)

%.o:	%.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f Doxyfile.bak

cleanall:	clean
	rm -f $(TARGETS)
	rm -rf html
