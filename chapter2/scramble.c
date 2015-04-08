#include <stdio.h>

/* want to write a program that scrambles output! basically I want to 
 *  1. convert to lowercase if uppercase
 *  2. convert to upperase if lowercase
 *  3. reverse the lines
 *
 *  the idea is to make some really shitty encryption like thing */

#define MAXLINE 1000

int lowerupper(int c);
int mygetline(char line[], int lim);
void reverse(char forward[], char backward[], int lim);

main()
{
    int lim = MAXLINE;
    int len;

    char line[MAXLINE];
    char reversed[MAXLINE];

    while ((len = mygetline(line, lim)) > 0) {
        reverse(line, reversed, len);
        printf("%s", reversed);
    }
}

int lowerupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else if (c >= 'a' && c <= 'z')
        return c + 'A' - 'a';
    else
        return c;
}

int mygetline(char line[], int lim)
{
    int c,i;

    for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = lowerupper(c);
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void reverse(char forward[], char backward[], int len)
{
    int i;

    for (i=0; i <= len - 2; i++)
        backward[len - (i + 2)] = forward[i];
    backward[len-1] = '\n';
    backward[len] = '\0';
}

// yay it works and is useless
