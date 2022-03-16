vpath %.h ./hashlib/inc
HEADERS = adlerhash.h bernsteinhash.h
SRC = adler/adlerhash.c bernstein/bernsteinhash.c
INC=-I./hashlib/inc

default: hashlib

hashlib: $(SRC) $(HEADERS)
	gcc $(INC) -c $(SRC)
	ar -cvq hashlib.a *.o
	ls
