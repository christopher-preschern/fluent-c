SRC = fileapplication/filereader/filereader.c randomapplication/pseudorandom/pseudorandom.c main.c
INC = -I./randomapplication/inc -I./fileapplication/inc -I./hashlib
LIB = hashlib/hashlib.a

default: main-application

main-application: $(SRC)
	gcc $(INC) $(SRC) $(LIB) -o main-application
