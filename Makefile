CC = cc
CCFLAGS = -g -c
LFLAGS = -lcurl -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = main.c read.c fetch.c window.c
OBJ = main.o read.o fetch.o window.o

link: main.o read.o fetch.o window.o
	$(CC) -o test $(OBJ) $(LFLAGS)

compile: main.c read.c fetch.c window.c
	$(CC) $(CCFLAGS) $(SRC)

buildfetcher:
	$(CC) -o fetch fetch.c -lcurl

buildwindow:
	$(CC) -o window window.c -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	./test

clean:
	rm ./test
