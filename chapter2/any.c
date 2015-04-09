#include <stdio.h>

// this function will take two strings, and return the first location in the string s1
// where ANY character from the string s2 occurs. I think this is pretty trivial based on the
// functions I wrote for the previous question

#define MAXLINE 1000

int any(char s1[], char s2[]);
int in(char s1[], char s);
int mygetline(char s[], int lim);

main()
{
    int len, i;
    char input[MAXLINE];
    char test[MAXLINE] = "t";

    while ((len = mygetline(input, MAXLINE)) > 0) {
        printf("First occurrence %d\n", any(input,test));
    }
}

int any(char s1[], char s2[]) // returns index of an occurance of a character in s2 or -1 if none
{
    int i;

    for (i = 0; s1[i] != '\0'; i++) {
        if (in(s2, s1[i]) == 1) {
            return i;
            break;
        }
    }
    return -1;
}
        
int in(char s1[], char s) // returns 1 if s in s1, else 0
{
    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s) {
            return 1;
            break;
        }
    }
    return 0;
}

int mygetline(char s[], int lim)
{
    int c,i;

    for (i=0; (c=getchar()) != EOF && c != '\n' && i<lim-1; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

