#include "user.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_USERS 50

struct ITERATOR
{
  int currentPosition;
  char currentElement[MAX_SIZE];
};

typedef struct
{
  char name[MAX_SIZE];
  char pwd[MAX_SIZE];
}USER;

static USER userList[MAX_USERS];

static void logError(char* username, char* pwd)
{
  char logString[200];
  sprintf(logString, "Failed login. User:%s, Pwd:%s\n", username, pwd);
  FILE* f = fopen("logfile", "a+");
  fwrite(logString, 1, strlen(logString), f);
  fclose(f);
}

bool authenticateUser(char* username, char* pwd)
{
  assert(username);
  assert(pwd);
  
  for(int i=0; i<MAX_USERS; i++)
  {
    if(strcmp(username, userList[i].name) == 0)
    {
      if(strcmp(pwd, userList[i].pwd) == 0)
      {
        return true;
      }
      else
      {
        logError(username, pwd);
      }
    }
  }
  return false;
}

static bool userExists(char* username)
{
  for(int i=0; i<MAX_USERS; i++)
  {
    if(strcmp(username, userList[i].name) == 0)
    {
      return true;
    }
  }
  return false;
}

ERROR_CODE addUser(char* username, char* pwd)
{
  assert(username);
  assert(pwd);
  
  if(userExists(username))
  {
    return USER_ALREADY_EXISTS;
  }
  
  for(int i=0; i<MAX_USERS; i++)
  {
    if(strcmp(userList[i].name, "") == 0)
    {
      strcpy(userList[i].name, username);
      strcpy(userList[i].pwd, pwd);
      return USER_SUCCESSFULLY_ADDED;
    }
  }
  
  return USER_ADMINISTRATION_FULL;
}

ITERATOR createIterator()
{
  ITERATOR iterator = (ITERATOR) calloc(sizeof(struct ITERATOR),1);
  return iterator;
}

char* getNextElement(ITERATOR iterator)
{
  if(iterator->currentPosition < MAX_USERS)
  {
    strcpy(iterator->currentElement, userList[iterator->currentPosition].name);
    iterator->currentPosition++;
  }
  else
  {
    strcpy(iterator->currentElement, "");
  }
  return iterator->currentElement;
}

void destroyIterator(ITERATOR iterator)
{
  free(iterator);
}

