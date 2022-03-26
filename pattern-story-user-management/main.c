#include <stdio.h>
#include <string.h>
#include "user.h"

int main()
{
  char* element;
  addUser("A", "pass");
  addUser("B", "pass");
  addUser("C", "pass");

  ITERATOR it = createIterator();
  
  while(true)
  {
    element = getNextElement(it);
	if(strcmp(element, "") == 0)
	{
	  break;
	}
	
    printf("User: %s ", element);
    printf("Authentication success? %d\n", authenticateUser(element, "pass"));
  }
  
  destroyIterator(it);
  printf("successfully worked with the user management system\n");
  return 0;
}

