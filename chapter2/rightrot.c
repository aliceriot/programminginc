#include <stdio.h>

// this returns the value of the integer X rotated to the right by n bit
// positions...what does this mean?















// ok so I read the wikipedia article and it gave this function:

unsigned int rotr(unsigned int value, int shift)
{
    return (value >> shift) | (value << (sizeof(value) * CHAR_BIT - shift));
}


