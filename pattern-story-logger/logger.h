#ifndef LOGGER_H
#define LOGGER_H
#include <stdbool.h>

/* Logs the current timestamp followed by the provided string. The string must be
valid until this function returns. The provided module identifies the software-
module which calles this function. */
void logging(const char* module, const char* text);

/* Enables printing output for the provided module. */
bool enableModule(const char* module);

/* All future log messages will be logged to stdout */
void logToStdout();

/* All future log messages will be logged to a file */
void logToFile();
#endif
