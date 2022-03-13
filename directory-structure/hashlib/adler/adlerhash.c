#include "adlerhash.h"

unsigned int adler32hash(const char* buffer, int length)
{
  unsigned int s1=1;
  unsigned int s2=0;
  int i=0;
  
  for(i=0; i<length; i++)
  {
     s1=(s1+buffer[i]) % 65521;
     s2=(s1+s2) % 65521;
  }
  return (s2<<16) | s1;
}
