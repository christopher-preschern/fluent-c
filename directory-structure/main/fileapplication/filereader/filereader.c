#include <stdio.h>
#include "filereader.h"

void getFileContent(char* buffer, int length)
{
  FILE* file = fopen("SomeFile", "rb");
  fread(buffer, length, 1, file);
  fclose(file);
}
