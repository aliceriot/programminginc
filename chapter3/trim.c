#include <stdio.h>
#include <string.h>
#include "utility.h"

#define MAXLINE 1000

int trim(char s[]);

main()
{
    int len;
    int limit = MAXLINE;
    char s[MAXLINE];

    while ((len = mygetline(s,limit)) > 0) {
        trim(s);
        printf("%s\n",s);
    }
}

int trim(char s[]) // trims whitespace from the end of lines
{
    int n;

    for (n = strlen(s)-1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }
    s[n+1] = '\0';
    return n;
}
