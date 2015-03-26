#include <stdio.h>

/* ok so here we want to modify the program so that it returns
 * the length of the longest line, but we don't necessarily need
 * all of the text (1000 characters is plenty)
 */

#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

// print longest input line
int main(void)
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
    int c, i, j;

    // hooray for stupid typos! yesss!

    for (i=0,j=0; (c=getchar())!=EOF && c!='\n'; ++i) {
        if (i<lim-1)
            s[++j] = c;
    }
    if (c == '\n') {
        if (i <= lim-1) {
            s[j++] = c;
        }
        ++i;
    }
    s[j] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
