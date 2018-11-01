# Makefile

# variáveis
CPP = g++

OBJ = p2.o grafo.o

# dependências
p2: $(OBJ)
	$(CPP) $(OBJ) -o p2
	
p2.o: p2.cpp
	$(CPP) $(CPPFLAGS) -c p2.cpp -o p2.o

grafo.o: grafo.cpp grafo.hpp
	$(CPP) $(CPPFLAGS) -c grafo.cpp -o grafo.o

all: p2

clean:
	rm -f *.o
	
