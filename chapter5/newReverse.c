#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char *input, char *output);

void main()
{
    char teststring[] = "let's reverse this, shall we?";
    printf("%s", teststring);

    char revstring[MAXLINE];
    reverse(teststring, revstring);
    printf("\n%s", revstring);
}

void reverse(char *input, char *output)
{
    char *p;
    p = input;
    while (*p != '\0') {
        p++;
    }
    p--;
    while (p != input) {
        *output = *p;
        output++; p--;
    }
    *output = *p;
}
