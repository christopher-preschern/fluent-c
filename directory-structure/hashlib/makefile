HEADERS = adlerhash.h bernsteinhash.h
SRC = adler/adlerhash.c bernstein/bernsteinhash.c

default: hashlib

hashlib: $(SRC) $(HEADERS)
	gcc -o $(SRC)
	ls
	ar -cvq hashlib.a *.o
	ls
