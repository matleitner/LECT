CXX = g++
CXXFLAGS = -Wall -Wextra -Wfatal-errors -ggdb -pthread -I../support/include
LDFLAGS = -pthread -lm

TARGETS = decrementer

.PHONY:	all clean cleanall

all: $(TARGETS)

$(TARGETS):	%: %.o 
		g++ -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o

cleanall:	clean
	rm -f $(TARGETS) 
