/* max. size of string parameters (including NULL-termination) */
#define STRING_SIZE 100

/* Error codes returned by this registry */
typedef enum
{
  OK,
  CANNOT_ADD_KEY
}RegError;

/* Handle for registry keys */
typedef struct Key* RegKey;

/* Create a new registry key identified via the provided 'key_name' (must not be NULL,
   max. STRING_SIZE characters).  Returns a handle to the key or NULL on error. */
RegKey createKey(char* key_name);

/* Store the provided 'value' (must not be NULL, max. STRING_SIZE characters) to
   the 'key' (MUST NOT BE NULL) */
void storeValue(RegKey key, char* value);
  
/* Make the 'key' (must not be NULL) available for being read.
   Returns OK if no problem occurs or CANNOT_ADD_KEY if the 
   registry is full and no more keys can be released. */
RegError releaseKey(RegKey key);
