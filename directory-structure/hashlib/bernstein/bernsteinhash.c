#include "bernsteinhash.h"

unsigned int bernsteinHash(const char* buffer, int length)
{
    unsigned int hash = 5381;
    int i;
    for(i=0; i<length; i++)
    {
        hash = 33 * hash ^ buffer[i];
    }
    return hash;
}
