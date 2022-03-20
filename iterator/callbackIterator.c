#define MAX_NAME_LENGTH 50
#define MAX_PWD_LENGTH 50
#define MAX_USERS 5

#include <stddef.h>
#include "callbackIterator.h"


struct ACCOUNT
{
  char loginname[MAX_NAME_LENGTH];
  char password[MAX_PWD_LENGTH];
  int nextPosition;
};


/* for simplicity reasons, we don't have a linked list with pointers, but static index info */
static struct ACCOUNT accountData[MAX_USERS] = {{"Y","Y",1}, {"B","B",2}, {"C","C",3}, {"X","X",4}, {"Y","Y",0}};

static struct ACCOUNT* getNext(struct ACCOUNT* current)
{
  if(current->nextPosition == 0)
  {
    return NULL;
  }
  else
  {
    return &accountData[current->nextPosition];
  }
}


void iterateLoginNames(FP_CALLBACK callback, void* arg)
{
  struct ACCOUNT* element = &accountData[0];
  while(element != NULL)
  {
    callback(element->loginname, arg);
    element = getNext(element);
  }
}





