#ifndef FILEACCESS_H
#define FILEACCESS_H

/* Opens the logfile at the first call.
Works on Linux and on Windows systems */
void* initiallyOpenLogFile();

/* Writes the provided buffer to the logfile.
Works on Linux and on Windows systems */
void writeLogFile(void* fileDescriptor, const char* buffer);

#endif
