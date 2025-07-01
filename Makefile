CC = cc
SRCS = $(wildcard src/*.c)
#OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst src/%.c,build/%.o,$(SRCS))
EXEC = realedu
BUILD_DIR = build

CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lcurl

.PHONY: all clean

all: $(BUILD_DIR)/$(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(EXEC): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/window.o: src/window.c include/window.h
$(BUILD_DIR)/fetch.o: src/fetch.c include/fetch.h
$(BUILD_DIR)/read.o: src/read.c include/read.h
$(BUILD_DIR)/book.o: src/book.c include/book.h

run:
	./$(BUILD_DIR)/$(EXEC)

clean:
	rm -rf $(BUILD_DIR)
