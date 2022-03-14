HEADERS = driver.h EthIOCTL.h UsbIOCTL.h
VPATH /home/runner/work/fluent-c/fluent-c/flexible-api 

default: flexible-api

flexible-api: flexible-api.o
	gcc flexible-api.o -o flexible-api

flexible-api.o: ethDriver.c $(HEADERS)
	gcc -c ethDriver.c -o flexible-api.o

clean:
	-rm -f flexible-api.o
	-rm -f flexible-api
