CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-result

all: main

main: main.c funcagenda.h functodo.h
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f main