#include <stdio.h>

int bitcount(unsigned x); // counts the number of bits set to '1' in the argument

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
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01)
            b++;
    }
    return b;
}
