#include <stdio.h>

// program to count blanks, tabs, and newlines in a file
// and then tell you about it! woohoo

main()
{
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;
    int c;

    while ((c = getchar()) != EOF){
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }

    printf("OK bud, we've got %d blanks, %d tabs, and %d newlines\n", blanks, tabs, newlines);
}


