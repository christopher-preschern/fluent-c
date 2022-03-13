#include <pseudorandom.h>
#include <adlerhash.h>

unsigned int getRandomNumber(int max)
{
  char* seed = "seed-text";
  unsigned int random = adler32hash(seed, 10);
  return random % max;  
}
