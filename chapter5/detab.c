#include <stdio.h>

/* ok so this here program is going to read in a file and then replace
 * occurrences of tabs in the input with spaces */

#define MAXLINE 1000  // max line length

int mygetline(char line[], int lim);
void tabtospace(char tabs[], char space[], int len);

main()
{
    int lim = MAXLINE;
    int len;

    char line[MAXLINE];
    char detabbed[MAXLINE];

    while ((len = mygetline(line, lim)) > 0) {
        tabtospace(line, detabbed, len);
        printf("%s", detabbed);
    }
}

int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i <lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void tabtospace(char tabs[], char space[], int len)
{
    int offset = 0; // this keeps track of the difference due to inserting
                    // extra space characters in the output string
    int i, j;

    for (i=0; i <= len; i++) {
        if (tabs[i] == '\t') {
            for (j = 1; j <= 4; j++) {
                space[i+offset] = ' ';
                offset++;
            }
        }
        else
            space[i+offset] = tabs[i];
    }
}
