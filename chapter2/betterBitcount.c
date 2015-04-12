#include <stdio.h>

int bitcount(unsigned x);

main()
{
    unsigned x = 144;

    printf("%d is the number of 1 bits in %d\n", bitcount(x), x);
}

int bitcount(unsigned x)
{
    int c;
    
    for (c = 0; x != 0; c++) {
        x &= (x-1);
    }
    return c;
}

// cool! So the better bitcount is quite a bit more elegant than the first one, but
// is it faster?
// if we do ``time ./a.out'' we can get a number for the running time for a program.
// betterBitcount: 0.001 total
// bitcount: 0.002 total
// so probably not haha
