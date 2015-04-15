#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);

main()
{
    char mystring[MAXLINE] = "just a \t \n test string \n \t\t\t";
    char copystring[MAXLINE];

    escape(mystring, copystring);

    printf("%s", copystring);
}

void escape(char s[], char t[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 10: 
                t[i] = 'N';
                break;
            case 9:
                t[i] = 'T';
                break;
            default:
                t[i] = s[i];
                break;
        }
    }
}

// not sure if I'm supposed to use a particular escaped character representation? whatevs.
