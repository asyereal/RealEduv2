CC = gcc
CCFLAGS = -g -c

SRC = main.c read.c
OBJ = main.o read.o

link: main.o read.o
	$(CC) -o test $(OBJ)

compile: main.c read.c
	$(CC) $(CCFLAGS) $(SRC)

run:
	./test

clean:
	rm ./test
