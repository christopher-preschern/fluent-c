SRC = adler/adlerhash.c bernstein/bernsteinhash.c
INC=-I./hashlib/inc

default: hashlib

hashlib: $(SRC)
	gcc $(INC) -c $(SRC)
	ar -cvq hashlib.a *.o
