# Makefile

# variáveis
CPP = g++
CPPFLAGS = -Wall -Wconversion

OBJ = main.o

# dependências
main: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o main

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

# memoria.o: memoria.cpp memoria.hpp
# 	$(CPP) $(CPPFLAGS) -c memoria.cpp -o memoria.o

all: main

clean:
	rm -f *.o
	
