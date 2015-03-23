#include <stdio.h>

// I messed this one up initially because I didn't have enough brackets!
// when in doubt assume you need more brackets!

main ()
{
    int c;
    int empty;

    int test = ' ';

    while ((c = getchar()) != EOF) {
        if (c == 32) {
            if (empty == 1)
                test = 1;
            else {
                empty = 1;
                putchar(' ');
            }
        }
        else {
            putchar(c);
            empty = 0;
        }
    }
    printf("Just a test %d", test);
}
        
            

