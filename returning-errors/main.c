#include "registry.h"
#include <stdio.h>

int main()
{
  RegKey my_key = createKey("my-key");
  if(my_key == NULL)
  {
    printf("Cannot create key\n");
  }

  storeValue(my_key, "A");

  RegError err = releaseKey(my_key);
  if(err == CANNOT_ADD_KEY)
  {
    printf("Key cannot be relased, because the registry is full\n");}
  }
