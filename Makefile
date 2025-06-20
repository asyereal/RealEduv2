CC = cc

SRCS = main.c read.c fetch.c window.c
OBJS = $(SRCS:.c=.o)
EXEC = test

CFLAGS = -Wall -Wextra -g
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lcurl

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

window.o: window.c window.h
	$(CC) $(CFLAGS) -c $< -o $@

fetch.o: fetch.c fetch.h
	$(CC) $(CFLAGS) -c $< -o $@

read.o: read.c read.h
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(EXEC)

clean:
	rm $(EXEC) 
	rm ${OBJS}
