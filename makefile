CC=g++
CPPFLAGS= -Wall -g -std=c++0x

SRC= main.cpp util.cpp
HDR= graph.h util.h

OBJ=$(SRC:.cpp=.o)

prog: $(OBJ) $(HDR)
	$(CC) -o graph $(CPPFLAGS) $^ && ./graph

%.o: %.cpp $(HDR)
	$(CC) -c -o $@ $< $(CPPFLAGS)

.PHONY: clean

clean:
	rm -f *.o graph
