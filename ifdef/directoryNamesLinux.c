#ifdef __unix__
  #include "directoryNames.h"
  #include <string.h>
  #include <stdio.h>
  #include <stdlib.h>

  void getHomeDirectory(char* dirname)
  {
      sprintf(dirname, "%s%s", getenv("HOME"), "/newdir/");
  }

  void getWorkingDirectory(char* dirname)
  {
    strcpy(dirname, "newdir/");
  }
#endif
