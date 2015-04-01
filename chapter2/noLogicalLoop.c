#include <stdio.h>

// we'll do this in our copy program, as a small example

#define MAXLINE 1000

int mygetline(char line[], int limit);

main()
{
    char line[MAXLINE];
    int limit = MAXLINE;
    int len;

    while ((len = mygetline(line, limit)) > 0) {
        printf("%s", line);
    }
}

int mygetline(char line[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF; i++) {
        if (c != '\n') {
            if (i < lim -1)
                line[i] = c;
        }
        else {
            if (c = '\n') {
                line[i] = c;
                i++;
            }
            line[i] = '\0';
            return i;
        }
    }
}

// made it work ugh
