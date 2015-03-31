#include <stdio.h>

/* this is program to 'fold' long lines onto two lines, and I think we're going to do 80
 * characters/line
 * */

#define MAXLINE 1000  // not going to bother with lines longer than 1000
#define OUTPUTMAXLINE 1020  // longer incase input is actually 1000 characters
#define SPLIT 79 // number of characters per output line (indexed from 0, so 79 == 80 characters per line

int mygetline(char line[], int maxline);
void foldit(char old[], char new[], int length);

main()
{
    int lim = MAXLINE;
    int len;

    char before[MAXLINE];
    char after[OUTPUTMAXLINE];

    while ((len = mygetline(before, lim)) > 0) {
        foldit(before,after,len);
        printf("%s", after);
    }
}

int mygetline(char before[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; i++)
        before[i] = c;
    if (c == '\n') {
        before[i] = c;
        i++;
    }
    before[i] = '\0';
    return i;
}

void foldit(char old[], char new[], int length)
{
    int i, offset, count;
    offset = count = 0;

    for (i = 0; i <= length; i++) {
        if (count != SPLIT) {
            new[i+offset] = old[i];
            count += 1;
        }
        else if (count == SPLIT) {
            new[i+offset] = old[i];
            offset += 1;
            new[i+offset] = '\n';
            count = 0;
        }
    }
}
            
// I think it works! hahahaha!
