HEADERS = adlerhash.h bernsteinhash.h
SRC = adler/adlerhash.c bernstein/bernsteinhash.c
INC=-I./inc

default: hashlib

hashlib: $(SRC) $(HEADERS)
	gcc -o $(SRC)
	ls
	ar -cvq hashlib.a *.o
	ls
