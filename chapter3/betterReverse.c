#include <stdio.h>
#include <string.h>

void reverse(char s[]);

main()
{
    char mystring[1000] = "just trying out reversing this";

    printf("%s\nbecomes\n",mystring);

    printf("That string is %d long\n",strlen(mystring));
    reverse(mystring);
    printf("%s\n", mystring);
}

void reverse(char s[])
{
    int c,i,j;

    for (i =0, j=strlen(s)-1;i<j; i++,j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// nice!
