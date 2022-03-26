#include "logger.h"
#include "fileAccess.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#define MODULE_SIZE 20
#define LIST_SIZE 10
typedef void (*logDestination)(const char*);
void stdoutLogging(const char* buffer);
static logDestination fp = stdoutLogging;

typedef struct
{
  char module[MODULE_SIZE];
}LIST;

static LIST list[LIST_SIZE] = {{""}};

bool enableModule(const char* module)
{
  for(int i=0; i<LIST_SIZE; i++)
  {
    if(strcmp(list[i].module, "") == 0)
    {
      strcpy(list[i].module, module);
      return true;
    }
    if(strcmp(list[i].module, module) == 0)
    {
      return false;
    }
  }
  return false;
}

bool isInList(const char* module)
{
  for(int i=0; i<LIST_SIZE; i++)
  {
    if(strcmp(list[i].module, module) == 0)
    {
      return true;
    }
  }
  return false;
}

void stdoutLogging(const char* buffer)
{
  printf(buffer);
}

void fileLogging(const char* buffer)
{
  void* fileDescriptor = initiallyOpenLogFile();
  writeLogFile(fileDescriptor, buffer);
}

void logToStdout()
{
  fp = stdoutLogging;
}

void logToFile()
{
  fp = fileLogging;
}

#define BUFFER_SIZE 100
void logging(const char* module, const char* text)
{
  char buffer[BUFFER_SIZE];
  time_t mytime = time(NULL);
  if(isInList(module))
  {
    sprintf(buffer, "%s %s\n", ctime(&mytime), text);
    fp(buffer);
  }
}
