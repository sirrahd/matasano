CC = gcc
CFLAGS = -g
LIBS = -lm

FILES = hex.c base64.c
TEST_FILES = hex_test.c base64_test.c test.c


test: $(FILES)
	$(CC) -o matasano_test $(CFLAGS) $(LIBS) $(FILES) $(TEST_FILES)

clean:
	rm *.o
