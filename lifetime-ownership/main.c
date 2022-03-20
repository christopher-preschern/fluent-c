#include "driver.h"

int main()
{
  SENDER s = openSender("192.168.0.1");
  char* dataToSend = "Hello World!";
  char* pointer = dataToSend;
  while(*pointer != '\0')
  {
    sendByte(s, *pointer);
    pointer++;
  }
  closeSender(s);
}
