#include <stdio.h>

// we want to write a function which will delete each character in s1 which matches
// any character in s2. ok!

#define MAXLINE 1000

void squeeze(char s1[], char s2[]);
int in(char string[], char s);
int mygetline(char s[], int lim);

main()
{
    int len;
    int i;
    char input[MAXLINE];
    char forbidden[MAXLINE] = "stuff";

    while ((len = mygetline(input, MAXLINE)) > 0) {
        squeeze(input, forbidden);
        printf("%s",input);
    }
}


void squeeze(char s1[], char s2[])
{
    int i,j;

    for (i = j = 0; s1[i] != '\0'; i++) {
        if (in(s2,s1[i]) == 0) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int in(char string[], char s)
{
    int i;
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == s) {
            return 1;
            break;
        }
    }
    return 0;
}

int mygetline(char s[], int lim)
{
    int c,i;

    for (i=0; (c=getchar()) != EOF && c != '\n' && i < lim -1; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// wow I wrote this and it worked first try! damn alice you sure can write that c code!
