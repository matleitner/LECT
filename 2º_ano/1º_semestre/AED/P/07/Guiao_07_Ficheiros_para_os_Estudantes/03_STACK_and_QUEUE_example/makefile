CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

TARGET = tests

SRC = \
	Date.c \
	Person.c \
	PointersQueue.c \
	PointersStack.c \
	Tests.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all

.PHONY: all clean re

