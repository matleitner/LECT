CXX = g++
CXXFLAGS = -Wall -ggdb -pthread -I../support
LDFLAGS = -L../support -lsupport -pthread -lm

TARGETS = sig1 sig2

.PHONY:	all clean cleanall

all: $(TARGETS)

$(TARGETS):	%: %.o 
		g++ -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o

cleanall:	clean
	rm -f $(TARGETS) 
