#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int mygetline(void);
void copy(void);

main()
{
    int len;
    extern int max; // ah, so actually these 'extern' definitions aren't necessary, since
    extern char longest[]; // we have the external variables declared earlier than where they 
                           // there are used in functions
    max = 0;
    while ((len = mygetline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int mygetline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; i++)
        line [i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;
    extern char line[], longest[];
    
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
