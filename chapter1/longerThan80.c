#include <stdio.h>

/* this will print all lines in the input that are longer than 80 characters!
 * nice */

#define MAXLINE 1000
#define CUTOFF 80

int mygetline(char line[], int maxline);

int main(void)
{
    int len;
    char line[MAXLINE];
    
    while ((len =  mygetline(line, MAXLINE)) > 0){
        if (len > CUTOFF)
            printf("%s", line); // don't need to print \n, as we stick it on the string in mygetline
    }
}

int mygetline(char s[], int lim)
{
    int c,i;

    for (i=0; i <lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
        

