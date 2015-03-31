#include <stdio.h>

/* ok so we want to strip all comments from a c file!
 * handy? maybe... */

#define MAXLINE 1000

int incomment =0;

int mygetline(char line[], int maxline);
void nocomment(char input[], char output[], int len);

main()
{
    int len;
    int lim = MAXLINE;

    char input[MAXLINE];
    char output[MAXLINE];

    while ((len = mygetline(input, lim)) > 0) {
        nocomment(input, output, len);
        printf("%s", output);
    }
}

int mygetline(char line[], int maxline)
{
    int i,c;

    for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void nocomment(char input[], char output[], int len)
{
    extern int incomment;
    int i;

    // this would probably be more elegantly expressed with a 'case' statement

    for (i=0; i <= len; i++) {
        if (input[i] == '/' && input[i+1] == '*') {
            output[i] = '\n';
            output[i+1] = '\0';
            incomment = 1;
            i = len;
        }
        else if (input[i] == '*' && incomment == 1) {
            output[i] = '\n';
            output[i+1] = '\0';
            i = len;
        }
        else if (input[i] == '/' && input[i+1] == '/') {
            output[i] = '\n';
            output[i+1] = '\0';
            i = len;
        }
        else if (incomment == 1) {
            if (input[i] == ' ')
                output[i] = input[i];
            else {
                output[i] = input[i];
                incomment = 0;
            }
        }
        else
            output[i] = input[i];
    }
}
    
// it works! yesss! although it doesn't really handle some things well - comment 
// lines are still left in, for instance
