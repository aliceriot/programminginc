#include <stdio.h>

#define MAXLINE 1000

// we'd like to convert an integer to a string, recursively!
// following the outline of the book's 'printd' function

void intToString(int x, char s[]);

main()
{
    int i = -324;
    char s[MAXLINE];

    intToString(i,s);
    printf("%s\n", s);
}

// this works! yeah!
void intToString(int x, char s[])
{
    
    static iter = 0;

    if (x < 0) {
        s[iter++] = '-';
        x = -x;
    }

    if (x / 10)
        intToString(x / 10, s);
    s[iter++] = (x % 10) + '0';

    s[iter] = '\0';

}
