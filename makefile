CC=g++
FLAGS= -std=c++14 -Wall
COMPILE=$(CC) $(FLAGS)

all: make

make: unitellertesttask

unitellertesttask: unitellertesttask.o id.o
	$(CC) unitellertesttask.o id.o -o unitellertesttask_gcc.exe

id.o: id.h id.cpp
	$(COMPILE) -c id.cpp -o id.o

unitellertesttask.o: unitellertesttask.cpp
	$(COMPILE) -c unitellertesttask.cpp -o unitellertesttask.o

clean:
	rm -rf all *.o *.lib

remake: clean make
