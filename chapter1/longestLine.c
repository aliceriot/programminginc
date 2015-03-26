#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

// print longest input line
main()
{
    int len; // current length
    int max; // max so far
    char line[MAXLINE]; //current input
    char longest[MAXLINE]; //longest one yet

    max = 0;

    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
