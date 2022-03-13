#include <stdio.h>
#include <stdlib.h>
#include <adlerhash.h>
#include <bernsteinhash.h>
#include <filereader.h>
#include <pseudorandom.h>

int main(int argc, char* argv[])
{
  char* buffer = malloc(100);
  getFileContent(buffer, 100);

  unsigned int hash = adler32hash(buffer, 100);
  printf("Adler32 hash value: %u\n", hash);

  hash = bernsteinHash(buffer, 100);
  printf("Bernstein hash value: %u\n", hash);

  unsigned int random = getRandomNumber(50);
  printf("Random value: %u\n", random);

  return 0;
}
