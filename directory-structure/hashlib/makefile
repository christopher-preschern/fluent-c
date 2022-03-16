SRC = adler/adlerhash.c bernstein/bernsteinhash.c
INC=-I./inc

default: hashlib

hashlib: $(SRC)
	gcc $(INC) -c $(SRC)
	ar -cvq hashlib.a *.o
