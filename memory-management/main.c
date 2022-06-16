#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <assert.h>
#include <stdbool.h>


#define ELEMENT_SIZE 255
#define MAX_ELEMENTS 10

typedef struct
{
  bool occupied;
  char memory[ELEMENT_SIZE];
}PoolElement;

static PoolElement memory_pool[MAX_ELEMENTS];

void* poolTake(size_t size)
{
  if(size <= ELEMENT_SIZE)
  {
    for(int i=0; i<MAX_ELEMENTS; i++)
    {
      if(memory_pool[i].occupied == false)
      {
        memory_pool[i].occupied = true;
        return &(memory_pool[i].memory);
      }
    }
  }
  return NULL;
}

void poolRelease(void* pointer)
{
  for(int i=0; i<MAX_ELEMENTS; i++)
  {
    if(&(memory_pool[i].memory) == pointer)
    {
      memory_pool[i].occupied = false;
      return;
    }
  }
}


/* Allocates memory and asserts if no memory is available */
void* mallocWrapper(size_t size)
{
  void* pointer = malloc(size);
  assert(pointer);
  return pointer;
}

/* Deallocates the memory of the provided 'pointer' */
void freeWrapper(void *pointer)
{
  free(pointer);
}




/* Performs a Caesar encryption with the fixed key 3.
    The parameter 'text' must contain a text with only capital letters.
    The parameter `length' must contain the length of the text excluding NULL termination. */
void caesar(char* text, int length)
{
   int i;
   for(i=0; i<length; i++)
   {
     text[i] = text[i]+3;

     /* if we shifted beyond the alphabetic characters, we restart at the beginning */
     if(text[i] > 'Z') 
     {
       text[i] = text[i] - 'Z' + 'A' - 1;
     }
   }
}


/* Returns the length of the file with the provided 'filename' */
int getFileLength(char* filename)
{
  FILE * f = fopen (filename, "r");
  fseek (f, 0, SEEK_END);
  int file_length = ftell (f);  /* copy return value of size_t to int */
  fclose(f);
  return file_length;
}



/* Stores the content of the file with the provided 'filename' into the provided 'buffer'
    (which has to be least of size 'file_length'). */
void readFileContent(char* filename, char* buffer, int file_length)
{
  FILE * f = fopen (filename, "r");
  fseek (f, 0, SEEK_SET);
  int read_elements = fread (buffer, 1, file_length, f);
  buffer[read_elements] = '\0';
  fclose (f);
}


/* For the provided file 'file_name', this function reads text from the file and prints
    the Caesar-encrypted text. This function is responsible for allocating and deallocating
    the required buffers for storing the file content */
void encryptCaesarFile(char* file_name)
{
  char* text = NULL;
  int size = getFileLength(file_name);
  if(size>0)
  {
  text = mallocWrapper(size);
  if(text != NULL)
  {
    readFileContent(file_name, text, size);
    caesar(text, strnlen(text, size));
    printf("Encrypted text: %s", text);  
  } 
  freeWrapper(text);
  text = NULL;
  }
}

#define MAX_FILENAME_SIZE ELEMENT_SIZE

/* Prints the Caesar-encrypted 'file_name'.This function is responsible for allocating and
    deallocating the required buffers for storing the file content.
    Notes: The file name must be all capital letters and we accept that the '.' of the file name
    will also be shifted by the Caesar encryption. */
void encryptCaesarFilename(char* file_name)
{
  char* buffer = poolTake(MAX_FILENAME_SIZE);
  strncpy(buffer, file_name, MAX_FILENAME_SIZE);
  caesar(buffer, strnlen(buffer, MAX_FILENAME_SIZE));
  printf("\nEncrypted file name: %s ", buffer);  
  poolRelease(buffer);
}


/* For all .txt files in the current directory, this function reads text from the file and prints
    the Caesar-encrypted text. */
void encryptDirectoryContent()
{
  struct dirent *directory_entry;
  DIR *directory = opendir(".");
  while ((directory_entry = readdir(directory)) != NULL)
  {
    encryptCaesarFilename(directory_entry->d_name);
    encryptCaesarFile(directory_entry->d_name);
  }
  closedir(directory);
}

int main()
{
  chdir(".\\text");
  encryptDirectoryContent();
  printf("\nSuccessfully encrypted directory content");
}

