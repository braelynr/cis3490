CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -g

all: main.c P11.c P12.c P21.c
	$(CC) $(CFLAGS) main.c P11.c P12.c P21.c -o bin/run

clean:
	rm bin/*
