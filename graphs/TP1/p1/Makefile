# Makefile

# variáveis
CPP = g++
CPPFLAGS = -Wall -Wconversion

OBJ = p1.o grafo.o

# dependências
p1: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o p1

p1.o: p1.cpp
	$(CPP) $(CPPFLAGS) -c p1.cpp -o p1.o

grafo.o: grafo.cpp grafo.hpp
	$(CPP) $(CPPFLAGS) -c grafo.cpp -o grafo.o

all: main

clean:
	rm -f *.o
	
