#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int mygetline(char *, int);

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                    printf("ungetch: too many characters\n");
            else
                        buf[bufp++] = c;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
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


