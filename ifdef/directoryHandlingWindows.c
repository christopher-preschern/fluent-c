#ifdef _WIN32
  #include <windows.h>

  void createNewDirectory(char* dirname)
  {
    CreateDirectory(dirname, NULL);
  }
#endif
