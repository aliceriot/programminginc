#include <stdio.h>

int bitcount(unsigned x); // counts the number of bits set to '1' in the argument

main()
{
    unsigned x = 144;

    printf("%d is the number of bits in %d\n",bitcount(x), x);
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
