#include <stdio.h>

int bitcount(unsigned x);

main()
{
    unsigned i;

    for (i = 0; i <= 21474836; i++) {
        bitcount(i);
    }

    printf("%d is the number of bits in %d\n",bitcount(i), i);
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
//
// I rewrote it to do a loop and ask about a ton of different integer values, and now
// it takes quite a long time to run.
//
// betterBitcount: 0.88s, 0.880 total
// bitcount: 2.28s, 2.282 total
//
// so the better algorithm is over twice as fast! Nice!
