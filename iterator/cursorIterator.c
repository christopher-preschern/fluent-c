#define MAX_NAME_LENGTH 50
#define MAX_PWD_LENGTH 50
#define MAX_USERS 5


#include <stdlib.h>
#include <string.h>
#include "cursorIterator.h"


struct ACCOUNT
{
  char loginname[MAX_NAME_LENGTH];
  char password[MAX_PWD_LENGTH];
  int nextPosition;
};


/* for simplicity reasons, we don't have a linked list with pointers, but static index info */
static struct ACCOUNT accountData[MAX_USERS] = {{"A","A",1}, {"B","B",2}, {"C","C",3}, {"X","X",4}, {"Y","Y",0}};

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



struct Iterator
{
  char buffer[MAX_NAME_LENGTH];
  struct ACCOUNT* element;
};


ITERATOR_HANDLE createIterator()
{
  struct Iterator* iterator = malloc(sizeof(struct Iterator));
  iterator->element = &accountData[0];
  return iterator;
}


void destroyIterator(ITERATOR_HANDLE iterator)
{
  free(iterator);
}



char* getNextLoginName(ITERATOR_HANDLE iterator)
{
  iterator->element = getNext(iterator->element);
  if(iterator->element != NULL)
  {
    strcpy(iterator->buffer, iterator->element->loginname);
    return iterator->buffer;
  }
  else
  {
    return NULL;
  }
}

