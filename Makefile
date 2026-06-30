CC=gcc
CFLAGS=-O2 -std=c23
BUILDDIR=bin

build: main.c match.c match.h
	mkdir -p $(BUILDDIR)
	$(CC) main.c $(CFLAGS) -o bin/match
test: test.c test.h match.c match.h
	mkdir -p $(BUILDDIR)
	$(CC) test.c $(CFLAGS) -o bin/test
	bin/test
