CXX = g++
CXXFLAGS = -Wall -ggdb -pthread -I../support
LDFLAGS = -L../support -lsupport -pthread -lm

TARGETS = pipe1 pipe2  pipe3

.PHONY:	all clean cleanall

all: $(TARGETS)

$(TARGETS):	%: %.o 
		g++ -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o

cleanall:	clean
	rm -f $(TARGETS) 
