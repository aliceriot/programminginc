#include <stdio.h>

// a little program to count the number of lines in the input

main()
{
    long numlines = 0;
    int c;

    while ((c = getchar()) != EOF){
        if (c == '\n')
            ++numlines;
    }
    printf("We've got %d lines, nice...\n", numlines);
}
