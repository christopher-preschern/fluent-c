#ifdef STORE_IN_CWD
  #include "directorySelection.h"
  #include "directoryNames.h"

  void getDirectoryName(char* dirname)
  {
    return getWorkingDirectory(dirname); 
  }
#endif

