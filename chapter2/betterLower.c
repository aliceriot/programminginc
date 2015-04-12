#include <stdio.h>

// a better upper -> lowercase!

#define MAXLINE 1000

int lower(int c);
int mygetlinelower(char line[], int limit);

main()
{
    int limit = MAXLINE;
    char line[MAXLINE];
    int len;

    while ((len = mygetlinelower(line, limit)) > 0)
        printf("%s", line);
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int mygetlinelower(char line[], int lim)
{
    int c,i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = lower(c);
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

