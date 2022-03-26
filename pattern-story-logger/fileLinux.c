#ifdef __unix__
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "fileAccess.h"
void* initiallyOpenLogFile()
{
  static int fd = 0;
  if(fd == 0)
  {
    fd = open("log.txt", O_RDWR | O_CREAT, 0666);
  }
  return fd;
}

void writeLogFile(void* fileDescriptor, const char* buffer)
{
  write((int)fileDescriptor, buffer, strlen(buffer));
}
#endif
