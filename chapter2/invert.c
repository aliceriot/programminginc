#include <stdio.h>

unsigned zeros(int p, int n); // n zeros in a one mask starting at position p
unsigned invert(unsigned x, int p, int n);

main()
{
    printf("615 6 3 is %d\n", invert(615,6,3));
}

unsigned zeros(int p, int n) // n zeros in a one mask starting at position p
{
    return (~0 << (p+1)) | (~(~0 << (p+1-n)));
}

unsigned invert(unsigned x, int p, int n)
{
    return (x ^ (~zeros(p,n)));
}

// it works! this is fun!
