CC=egcc
CFLAGS=-std=c11 -g
LIBS=-lm

SRC=$(wildcard *.c)
a.out: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm a.out
