#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int reverse(char s[], int len);

main()
{
    char s[] = "my test string";

    printf("%s\n", s);

    reverse(s, strlen(s) - 1);

    printf("%s\n", s);
}

// works!
int reverse(char s[], int last)
{
    int temp;
    int i;

    if (last > 0) {
        temp = s[0];
        for (i = 1; i <= last; i++)
            s[i-1] = s[i];
        s[last--] = temp;
        reverse(s, last);
    }
}


