#include <stdio.h>
#include "utility.h"

#define MAXLINE 1000

/* 
 * we want this one to basically do the same
 * thing as our 'fakeGrep' program, but we would
 * like for the strindex function to return the 
 * rightmost location where the query string
 * is found
 */

int strrindex(char source[], char search[]);

char pattern[] = "ould"; // our search pattern

main()
{
    char line[MAXLINE];
    int found = 0;

    while (mygetline(line, MAXLINE) > 0) {
        if (strrindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s); i >= 0; i--) {
        for (j=i, k = 0; t[k] != '\0' && s[j]==t[k]; j++,k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

