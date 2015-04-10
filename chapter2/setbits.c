#include <stdio.h>

// we want to write a function setbits(x,p,n,y) that returns x with the n bits
// that begin at position p set to the rightmost n bits of y, leaving the other bits
// unchanged

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned zeros(int p, int n); // n zeros in a one mask starting at position p

main()
{
    printf("785 5 3 45 is %d\n", setbits(785,5,3,45));
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & zeros(p,n)) | (getbits(y,n-1,n) << (p+1-n));
}

unsigned zeros(int p, int n) // n zeros in a one mask starting at position p
{
    return (~0 << (p+1)) | (~(~0 << (p+1-n)));
}

// oh my god it works
// what even
