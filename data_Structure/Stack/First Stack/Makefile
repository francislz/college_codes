# Makefile

# variáveis
CPP = g++
CPPFLAGS = -Wall -Wconversion

OBJ = main.o stack.o

# dependências
main: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o main
	
main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

stack.o: stack.cpp stack.hpp
	$(CPP) $(CPPFLAGS) -c stack.cpp -o stack.o

all: main

clean:
	rm -f *.o
	
