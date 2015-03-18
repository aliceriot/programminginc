#include <stdio.h>

/* it's gonna be interesting! we're going to print out a table
 * of temperature equivalents.... */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Welcome to the world of temperatures!\n\n");

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/* damn it's hard not to get excited about this stuff */
