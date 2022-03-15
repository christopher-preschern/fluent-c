/* Copies the path to a new directory with name "newdir"
   located in the user's home directory into 'dirname'.
   Works on Linux and Windows. */
void getHomeDirectory(char* dirname);

/* Copies the path to a new directory with name "newdir"
   located in the current working directory into 'dirname'.
   Works on Linux and Windows. */
void getWorkingDirectory(char* dirname);
