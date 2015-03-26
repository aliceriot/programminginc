#include <stdio.h>

/* this is going to remove trailing whitespace, and then 
 * also remove lines which are totally blank */

#define MAXLINE 1000

int mygetline(char line[], int max);
int clean(char dirty[], char clean[], int length);

main()
{
    int len;
    char line[MAXLINE];
    char cleaned[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (line[0] != '\n') {
            clean(line, cleaned, len);
            printf("%s", cleaned);
        }
    }
}

int mygetline(char s[], int lim)
{
    int c,i;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

int clean(char dirty[], char clean[], int len)
{
    int i,j,p;

    p = 0;

    for (i = len; i >=0; i--){
        if (p == 0)
            if (dirty[i] == '\n' || dirty[i] == '\t' || dirty[i] == ' ' || dirty[i] == '\0')
                j = i;
            else {
                p = 1;
                clean[i] = dirty[i];
            }
        else
            clean[i] = dirty[i];
    }
    clean[j] = '\n';
    clean[j+1] = '\0';
}

