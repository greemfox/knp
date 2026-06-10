СС=gcc
CFLAGS=-O2

build: match.c
	$(CC) match.c $(CFLAGS) -o match
test: test.c
	$(CC) test.c $(CFLAGS) -o test
	./test
