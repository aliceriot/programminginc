#include <stdio.h>

// going to loop through and print one word per line! weee

#define IN 1
#define OUT 0

main()
{
    int c, state;

    state == OUT;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            state = IN;
            putchar(c);
        }
        else if (c == ' ') {
            if (state != OUT) {
                state = OUT;
                putchar('\n');
            }
        }
    }
}
