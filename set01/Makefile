CC=gcc
CFLAGS=-std=c11 -g
LIBS=-lm

SRC=$(wildcard *.c)
HDR=$(wildcard *.h)
a.out: $(SRC) $(HDR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm a.out
