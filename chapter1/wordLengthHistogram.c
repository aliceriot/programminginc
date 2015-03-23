#include <stdio.h>

// this takes input on STDIN and produces a histogram of word lengths!
// I think I'm going to assume that words have a max length of 200 characters

main()
{
    int i,cur,c;
    cur = 0;

    float total = 0;

    int printCounter = 0;

    int wordCounts[200];

    for (i = 0; i < 200; ++i)
        wordCounts[i] = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t') {
            if (cur != 0) {
                ++wordCounts[cur];
                cur = 0;
                ++total;
            }
            else
                cur = 0;
        }
        else
            cur++;
    }

    // going to print histogram, currently it doesn't scale (so large word counts
    // will wrap to the next line, I tried to figure out a better way but am stymied
    // with int/float arithmetic on that front.

    printf("Length\tCount\n");

    for (i = 0; i < 200; i++) {
        if (wordCounts[i] != 0) {
            printf("%d\t",i);
            printCounter = wordCounts[i];
            while (printCounter != 0) {
                printf("-");
                --printCounter;
            }
            printf("\n");
        }
    }
}

