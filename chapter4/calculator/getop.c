#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;
    static char buff[MAXVAL];
    static int bufpos = 0;

    while ((s[0] = c =((bufpos >0) ? buff[--bufpos] : getchar())) == ' ' || c == '\t')
        ; // skip blanks
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = ((bufpos >0) ? buff[--bufpos] : getchar())))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = ((bufpos >0) ? buff[--bufpos] : getchar())))
            ;
    s[i] = '\0';
    if (c != EOF)
        buff[bufpos++] = c;
    return NUMBER;
}

