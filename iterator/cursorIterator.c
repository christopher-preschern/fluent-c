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

static struct ACCOUNT* getFirst()
{
    return &accoundData[0];
}

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


struct ITERATOR
{
  char buffer[MAX_NAME_LENGTH];
  struct ACCOUNT_NODE* element;
};

struct ITERATOR* createIterator()
{
  struct ITERATOR* iterator = malloc(sizeof(struct ITERATOR));
  iterator->element = getFirst();
  return iterator;
}

char* getNextLoginName(struct ITERATOR* iterator)
{
  if(iterator->element != NULL)
  {
    strcpy(iterator->buffer, iterator->element->loginname);
    iterator->element = getNext(iterator->element);
    return iterator->buffer;
  }
  else
  {
    return NULL;
  }
}

void destroyIterator(struct ITERATOR* iterator)
{
  free(iterator);
}

