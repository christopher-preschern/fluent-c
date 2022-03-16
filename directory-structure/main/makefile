SRC = fileapplication/filereader/filereader.c randomapplication/pseudorandom/pseudorandom.c
INC = -I/home/runner/work/fluent-c/fluent-c/directory-structure/main/randomapplication/inc -I/home/runner/work/fluent-c/fluent-c/directory-structure/main/fileapplication/inc -I/home/runner/work/fluent-c/fluent-c/directory-structure/main/hashlib
LIB = /home/runner/work/fluent-c/fluent-c/directory-structure/main/hashlib/hashlib.a

default: main-application

main-application: $(SRC)
	gcc $(INC) $(SRC) $(LIB) -o main-application
