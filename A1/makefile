CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -g

all: algo

algo: main.c P11.c P12.c
	$(CC) $(CFLAGS) main.c P11.c P12.c -o bin/run

clean:
	rm bin/*
