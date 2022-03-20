HEADERS = $(wildcard *.h)
SRC=$(wildcard *.c)

default: iterator

iterator: $(SRC) $(HEADERS)
	gcc -o $@ $^
