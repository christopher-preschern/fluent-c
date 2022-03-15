#ifdef _WIN32
  #include "directoryNames.h"
  #include <string.h>
  #include <stdio.h>
  #include <windows.h>

  void getHomeDirectory(char* dirname)
  {
    sprintf(dirname, "%s%s%s", getenv("HOMEDRIVE"), getenv("HOMEPATH"),
            "\\newdir\\");
    }

  void getWorkingDirectory(char* dirname)
  {
    strcpy(dirname, "newdir\\");
  }
#endif

