#include "logger.h"

int main()
{
  enableModule("MYMODULE");
  logging("MYMODULE", "Log to stdout");
  logToFile();
  logging("MYMODULE", "Log to file");
  logging("MYMODULE", "Log to file some more");
  return 0;
}
