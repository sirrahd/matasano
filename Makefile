IDIR=inc
SDIR=src
ODIR=obj
TDIR=test

CC=gcc
CFLAGS=-I$(IDIR) -std=gnu99
TFLAGS=-g
LIBS=-lm

_DEPS=base64.h hex.h xor.h common.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(TFLAGS)

$(ODIR)/%.o: $(TDIR)/%.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(TFLAGS)

_OBJ=base64.o hex.o xor.o common.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_TEST_OBJ=xor_test.o base64_test.o hex_test.o test.o
TEST_OBJ=$(patsubst %,$(ODIR)/%,$(_TEST_OBJ))

matasano_unittest: $(OBJ) $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

_S01C01=s01c01.o
S01C01=$(patsubst %,$(ODIR)/%,$(_S01C01))
matasano_s01c01: $(OBJ) $(S01C01)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

_S01C02=s01c02.o
S01C02=$(patsubst %,$(ODIR)/%,$(_S01C02))
matasano_s01c02: $(OBJ) $(S01C02)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

_S01C03=s01c03.o
S01C03=$(patsubst %,$(ODIR)/%,$(_S01C03))
matasano_s01c03: $(OBJ) $(S01C03)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

_S01C04=s01c04.o
S01C04=$(patsubst %,$(ODIR)/%,$(_S01C04))
matasano_s01c04: $(OBJ) $(S01C04)
	$(CC) -o $@ $^ $(CFLAGS) $(TFLAGS) $(LIBS)

clean:
	rm -fr $(ODIR) *~ core $(INCDIR)/*~ matasano_*
