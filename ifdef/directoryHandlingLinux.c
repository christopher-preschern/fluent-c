#ifdef __unix__
  #include <sys/stat.h>

  void createNewDirectory(char* dirname)
  {
    mkdir(dirname,S_IRWXU);
  }
#endif

