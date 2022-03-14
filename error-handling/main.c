#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define BUFFER_SIZE 1000
#define KEYWORD_ONE_FOUND_FIRST 1
#define KEYWORD_TWO_FOUND_FIRST 2
#define NO_KEYWORD_FOUND 3
#define ERROR 4

typedef struct
{
  FILE* file_pointer;
  char* buffer;
}FileParser;

int searchFileForKeywords(FileParser* parser)
{
  if(parser == NULL)
  {
    return ERROR;  
  }
  
  while(fgets(parser->buffer, BUFFER_SIZE, parser->file_pointer)!=NULL)
  {
    if(strcmp("KEYWORD_ONE\n", parser->buffer)==0)
    {
      return KEYWORD_ONE_FOUND_FIRST;
    }
    if(strcmp("KEYWORD_TWO\n", parser->buffer)==0)
    {
      return KEYWORD_TWO_FOUND_FIRST;
    }
  }
  return NO_KEYWORD_FOUND;
}

void cleanupParser(FileParser* parser)
{
  if(parser)
  {
    if(parser->buffer)
    {
      free(parser->buffer);
    }
    if(parser->file_pointer)
    {
      fclose(parser->file_pointer);
    }
    free(parser);
  }
}

FileParser* createParser(char* file_name)
{

  assert(file_name!=NULL && "Invalid filename");
  FileParser* parser = malloc(sizeof(FileParser));
  if(parser)
  {
    parser->file_pointer=fopen(file_name, "r");
    parser->buffer = malloc(BUFFER_SIZE);
    if(!parser->file_pointer || !parser->buffer)
    {
      cleanupParser(parser);
      return NULL;
    }
  }
  return parser;
}

int parseFile(char* file_name)
{
  int return_value;
  FileParser* parser = createParser(file_name);
  return_value = searchFileForKeywords(parser);
  cleanupParser(parser);
  return return_value;
}

int main()
{
  int return_value;
  return_value = parseFile("myfile.txt");
  printf("Return value: %i\n", return_value);
  return 0;
}

