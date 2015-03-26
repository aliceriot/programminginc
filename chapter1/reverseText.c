#include <stdio.h>

/* this will reverse test, I think how it will work is that I'll
 * take getline, and read in lines, and we'll print out a variation
 * of the copy string function, so there will be two character arrays
 * going on. as long as we pass in length from getline we should be
 * safe as far as copying the right characters from the end and so on */

#define MAXLINE 1000

int mygetline(char line[], int max);
int reverse(char forward[], char backward[], int length);

main()
{
    int len;
    char forward[MAXLINE];
    char backward[MAXLINE];
    char cleaned[MAXLINE];

    while ((len = mygetline(forward, MAXLINE)) > 0) {
        reverse(forward, backward, len);
        printf("%s", backward);
    }
}

int mygetline(char s[], int lim)
{
    int c,i;

    for (i=0; (c=getchar()) != EOF && c!='\n' && i < lim -1; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int reverse(char forward[], char backward[], int len) // pictures help yo!
{
    int i;

    for (i = 0; i <= len -2; i++)
        backward[len - (i + 2)] = forward[i];
    backward[len-1] = '\n';
    backward[len] = '\0';
}

