#include <stdio.h>

// exercise 1-9, we'd like to copy the input to our output, while replacing
// and occurences of tabs with '\t', and backspace with '\b', etc

main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == 116) 
            putchar('\t');
        if (c == 32)
            putchar('\\');
        else
            putchar(c);
    }
}

// makes it messy! nice! I guess that's fun?

