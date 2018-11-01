# Makefile

# variáveis
CPP = g++
CPPFLAGS = -Wall -Wconversion

OBJ = tp2.o grafo.o

# dependências
tp2: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o tp2

tp2.o: tp2.cpp
	$(CPP) $(CPPFLAGS) -c tp2.cpp -o tp2.o

grafo.o: grafo.cpp grafo.hpp
	$(CPP) $(CPPFLAGS) -c grafo.cpp -o grafo.o

all: main

clean:
	rm -f *.o
	
