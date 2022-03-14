HEADERS = 

default: error-handling

error-handling.o: main.c $(HEADERS)
    gcc -c main.c -o error-handling.o

error-handling: error-handling.o
    gcc error-handling.o -o error-handling

clean:
    -rm -f error-handling.o
    -rm -f error-handling
