#include <stdio.h>
#include "utility.h"
#include "atof.c"

#define MAXLINE 1000

main()
{
    double sum, atof(char s[]);
    char line[MAXLINE];
    int mygetline(char line[], int max);

    sum = 0;
    while (mygetline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
