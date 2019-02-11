CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -g

all: main.c P11.c P12.c P21.c P22.c
	$(CC) $(CFLAGS) main.c P11.c P12.c P21.c P22.c -lm -o run

clean:
	rm run
