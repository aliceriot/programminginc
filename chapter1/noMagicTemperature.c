#include <stdio.h>

// some quick definitions for readability

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    int fahr;

    printf("No magic here, folks!\n\n");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}
