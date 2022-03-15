#ifdef STORE_IN_HOME_DIR
  #include "directorySelection.h"
  #include "directoryNames.h"

  void getDirectoryName(char* dirname)
  {
    getHomeDirectory(dirname);
  }
#endif

