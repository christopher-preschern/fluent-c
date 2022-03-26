#ifdef _WIN32
#include <windows.h>
#include "fileAccess.h"

void* initiallyOpenLogFile()
{
  static HANDLE hFile = NULL;
  if(hFile == NULL)
  {
    hFile = CreateFile("log.txt", GENERIC_WRITE, 0, NULL,
                       CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
  }
  return hFile;
}

void writeLogFile(void* fileDescriptor, const char* buffer)
{
  WriteFile((HANDLE)fileDescriptor, buffer, strlen(buffer), NULL, NULL);
}
#endif
