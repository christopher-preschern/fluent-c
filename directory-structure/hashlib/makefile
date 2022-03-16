HEADERS = adlerhash.h bernsteinhash.h
SRC = adler/adlerhash.c bernstein/bernsteinhash.c
INC=-I/home/runner/work/fluent-c/fluent-c/directory-structure/hashlib/inc

default: hashlib

hashlib: $(SRC) $(HEADERS)
	gcc -o $(SRC)
	ls
	ar -cvq hashlib.a *.o
	ls
