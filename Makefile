СС=gcc
CFLAGS=-O2
BUILDDIR=bin

build: match.c
	mkdir -p $(BUILDDIR)
	$(CC) match.c $(CFLAGS) -o bin/match
test: test.c
	mkdir -p $(BUILDDIR)
	$(CC) test.c $(CFLAGS) -o bin/test
	bin/test
