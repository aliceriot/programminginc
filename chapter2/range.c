#include <stdio.h>
#include <limits.h>

main()
{
    printf("Char has %d bits, and can range from %d to %d.\n", CHAR_BIT, SCHAR_MIN, SCHAR_MAX);
    printf("Short can range from %d to %d.\n", SHRT_MIN, SHRT_MAX);
    printf("Int can range from %d to %d.\n", INT_MIN, INT_MAX);
    printf("Long can range from %d to %d.\n", LONG_MIN, LONG_MAX);
}
