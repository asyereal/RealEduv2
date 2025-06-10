CC = gcc
CCFLAGS = -g -c

SRC = main.c read.c fetch.c
OBJ = main.o read.o fetch.o

link: main.o read.o fetch.o
	$(CC) -o test $(OBJ) -lcurl

compile: main.c read.c fetch.c
	$(CC) $(CCFLAGS) $(SRC)

buildfetcher:
	$(CC) -o fetch fetch.c -lcurl

buildwindow:
	$(CC) -o window window.c -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	./test

clean:
	rm ./test
