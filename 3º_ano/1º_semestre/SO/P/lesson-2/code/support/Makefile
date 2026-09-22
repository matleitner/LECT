CXX = g++
CXXFLAGS = -Wall -ggdb -pthread 

TARGETS = libsupport.a

HEADERS = process.h utils.h dbc.h delays.h
OBJS = process.o utils.o delays.o

.PHONY:	all clean cleanall

all: $(TARGETS) clean

libsupport.a: $(OBJS)
	ar rcs $@ $^

%.o:	%.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o

cleanall:	clean
	rm -f $(TARGETS) 
