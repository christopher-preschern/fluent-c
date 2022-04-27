#ifndef USER_H
#define USER_H

#include <stdbool.h>

#define MAX_SIZE 50

/* Returns true if the provided username exists and if the provided password is
   correct for that user, returns false otherwise. Asserts in case of invalid
   input (NULL string). */
bool authenticateUser(char* username, char* pwd);

typedef enum{
  USER_SUCCESSFULLY_ADDED,
  USER_ALREADY_EXISTS,
  USER_ADMINISTRATION_FULL
}ERROR_CODE;

/* Adds a new user with the provided `username' and the provided password `pwd'
   (asserts on NULL). Returns USER_SUCCESSFULLY_ADDED on success, USER_ALREADY_EXISTS
   in case a user with the provided username already exists and USER_ADMINISTRATION_FULL
   in case no more users can be added. */
ERROR_CODE addUser(char* username, char* pwd);

typedef struct ITERATOR* ITERATOR;

/* Create an iterator instance.  Returns NULL on error. */
ITERATOR createIterator();

/* Retrieves the next element from an iterator instance. */
char* getNextElement(ITERATOR iterator);

/* Destroys an iterator instance. */
void destroyIterator(ITERATOR iterator);

#endif

