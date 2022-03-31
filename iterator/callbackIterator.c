#define MAX_NAME_LENGTH 50
#define MAX_PWD_LENGTH 50
#define MAX_USERS 5

#include <stddef.h>
#include "callbackIterator.h"


struct ACCOUNT
{
  char loginname[MAX_NAME_LENGTH];
  char password[MAX_PWD_LENGTH];
  struct ACCOUNT* next;
};

/* for simplicity reasons, we'll have a fixed set of list elements */
static struct ACCOUNT accountData1;
static struct ACCOUNT accountData2;
static struct ACCOUNT accountData3;

static void initList()
{
  strcpy(accountData1.loginname, "A");
  strcpy(accountData1.password, "A");
  accountData1.next = &accountData2;
  
  strcpy(accountData2.loginname, "B");
  strcpy(accountData2.password, "B");
  accountData2.next = &accountData3;
  
  strcpy(accountData3.loginname, "C");
  strcpy(accountData3.password, "C");
  accountData3.next = NULL;
}


[MAX_USERS] = {{"Y","Y",1}, {"B","B",2}, {"C","C",3}, {"X","X",4}, {"Y","Y",0}};

static struct ACCOUNT* getFirst(struct ACCOUNT* current)
{
  return &accountData1;
}

static struct ACCOUNT* getNext(struct ACCOUNT* current)
{
  return current->nextPosition;
}


void iterateLoginNames(FP_CALLBACK callback, void* arg)
{
  initList();
  
  struct ACCOUNT* element = &accountData[0];
  while(element != NULL)
  {
    callback(element->loginname, arg);
    element = getNext(element);
  }
}





