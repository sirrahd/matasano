IDIR=inc
SDIR=src
ODIR=obj
TDIR=test

CC=gcc
CFLAGS=-I$(IDIR) -std=gnu99
LIBS=-lm

_DEPS=base64.h hex.h xor.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=base64.o hex.o xor.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_TEST_OBJ=base64_test.o hex_test.o test.o
TEST_OBJ=$(patsubst %,$(ODIR)/%,$(_TEST_OBJ))

_SRC=base64.c hex.c xor.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_TEST_SRC=base64_test.c hex_test.c test.c
TEST=$(patsubst %,$(TDIR)/%,$(_TEST))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

matasano: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(TDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

matasano_test: $(OBJ) $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
