IDIR=inc
SDIR=src
ODIR=obj
TDIR=test

CC=gcc
CFLAGS=-I$(IDIR) -std=gnu99
TFLAGS=-g
LIBS=-lm

_DEPS=base64.h hex.h xor.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=base64.o hex.o xor.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_S01C01=s01c01.o
S01C01=$(patsubst %,$(ODIR)/%,$(_S01C01))

_S01C02=s01c02.o
S01C02=$(patsubst %,$(ODIR)/%,$(_S01C02))

_S01C03=s01c03.o
S01C03=$(patsubst %,$(ODIR)/%,$(_S01C03))

_TEST_OBJ=xor_test.o base64_test.o hex_test.o test.o
TEST_OBJ=$(patsubst %,$(ODIR)/%,$(_TEST_OBJ))

_SRC=base64.c hex.c xor.c s01c01.c s01c03.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

_TEST_SRC=xor_test.c base64_test.c hex_test.c test.c
TEST=$(patsubst %,$(TDIR)/%,$(_TEST))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(TFLAGS)

$(ODIR)/%.o: $(TDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(TFLAGS)

matasano_unittest: $(OBJ) $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

matasano_s01c01: $(OBJ) $(S01C01)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

matasano_s01c02: $(OBJ) $(S01C02)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

matasano_s01c03: $(OBJ) $(S01C03)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ matasano_*
