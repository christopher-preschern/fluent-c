HEADERS = directoryHandling.h directoryNames.h directorySelection.h
SRC=$(wildcard *.c)

default: ifdef

ifdef: $(SRC) $(HEADERS)
  gcc -o $@ $^
