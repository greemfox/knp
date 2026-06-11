СС=gcc
CFLAGS=-O2

build: match.c
	$(CC) match.c $(CFLAGS) -o bin/match
test: test.c
	$(CC) test.c $(CFLAGS) -o bin/test
	bin/test
