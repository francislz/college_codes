# Makefile

# variáveis
CPP = g++
CPPFLAGS = -Wall -Wconversion

OBJ = main.o geek.o

# dependências
main: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o main
	
main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

geek.o: geek.cpp geek.hpp
	$(CPP) $(CPPFLAGS) -c geek.cpp -o geek.o

all: main

clean:
	rm -f *.o
	
