#include <stdio.h>
#include <string.h>

void mystrcat(char *s, char *t);

void main()
{
    char teststring[1000] = "whoa its a string ";
    char addstring[] = "with even more string-ness!";

    mystrcat(teststring, addstring);
    printf("%s\n", teststring);
}

void mystrcat(char *s, char *t)
{
    s += strlen(s);
    while ((*s++ = *t++) != '\0')
        ;
}
