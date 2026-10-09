CXX = g++
CXXFLAGS = -Wall -Wextra -Wfatal-errors -Werror -ggdb -pthread -I../support/include
LDFLAGS = -pthread -lm

TARGETS = main
HEADERS = sos.h
OBJS = sos.o

.PHONY:	all clean cleanall

all: $(TARGETS)

$(TARGETS):	%:	%.o $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o:	%.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o Doxyfile.bak
	rm -f Doxyfile.bak

cleanall:	clean
	rm -f $(TARGETS)
	rm -rf html
