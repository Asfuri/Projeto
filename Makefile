CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-result

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f main