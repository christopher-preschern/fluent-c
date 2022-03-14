HEADERS = driver.h EthIOCTL.h UsbIOCTL.h

default: flexible-api

error-handling.o: main.c $(HEADERS)
	gcc -c ethDriver.c -o flexible-api.o

error-handling: flexible-api.o
	gcc flexible-api.o -o flexible-api

clean:
	-rm -f flexible-api.o
	-rm -f flexible-api
