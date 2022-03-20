#include <stdio.h>
#include <stdbool.h>
#include "indexAccess.h"
#include "cursorIterator.h"
#include "callbackIterator.h"


bool index_anyoneWithX()
{
  int i;
  for(i=0; i<MAX_USERS; i++)
  {
    char* loginName = getLoginName(i);    
    if(loginName[0] == 'X')
    {
      return true;
    }
  }
  return false;
}


bool cursor_anyoneWithX()
{
  char* loginName;
  ITERATOR_HANDLE iterator = createIterator();
  while(loginName = getNextLoginName(iterator))
  {
    if(loginName[0] == 'X')
    {
      destroyIterator(iterator);
      return true;
    }
  }
  destroyIterator(iterator);
  return false;
}


void findX(char* loginName, void* arg)
{
  bool* found = (bool*) arg;
  if(loginName[0] == 'X')
  {
    *found = true;
  }
}

void countY(char* loginName, void* arg)
{
  int* count = (int*) arg;
  if(loginName[0] == 'Y')
  {
    (*count)++;
  }
}

bool callback_iterate_anyoneWithX()
{
  bool found=false;
  iterateLoginNames(findX, &found);
  return found;
}

int callback_iterate_numberOfUsersWithY()
{
  int count=0;
  iterateLoginNames(countY, &count);
  return count;
}


int main()
{
  printf("Success - Index Access - Anyone with X? %d\n", index_anyoneWithX());
  printf("Success - Cursor Iterator - Anyone with X? %d\n", cursor_anyoneWithX());
  printf("Success - Callback Iterator - Anyone with X? %d\n", callback_iterate_anyoneWithX());
  printf("Success - Callback Iterator - Number of Y: %i\n", callback_iterate_numberOfUsersWithY());
  
  return 0;
}




