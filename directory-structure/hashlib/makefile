HEADERS = adlerhash.h bernsteinhash.h
SRC = adler/adlerhash.c bernstein/bernsteinhash.c
INC=-I/home/runner/work/fluent-c/fluent-c/directory-structure/hashlib/inc

default: hashlib

hashlib: $(SRC)
	gcc $(INC) -o $(SRC)
	ar -cvq hashlib.a *.o
	ls
