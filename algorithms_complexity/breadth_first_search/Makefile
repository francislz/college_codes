# Makefile

# variáveis
CPP = g++
CPPFLAGS = -Wall -Wconversion

OBJ = main.o list.o

# dependências
main: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o main
	
main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

list.o: list.cpp list.hpp
	$(CPP) $(CPPFLAGS) -c list.cpp -o list.o

all: main

clean:
	rm -f *.o
	
