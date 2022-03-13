#ifndef BERSTEINHASH_H
#define BERNSTEINHASH_H
/* Returns the hash value of the provided "buffer" of size "length".
   The hash is calculated according to the D.J. Bernstein algorithm. */
unsigned int bernsteinHash(const char* buffer, int length);
#endif
