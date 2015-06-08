#include <stdio.h>

int strend(char *s, char *t);

void main()
{
    char testone[] = "just a string with nothing interesting at the end";
    char endone[] = "at the end";
    char endtwo[] = "asdfasdf";


    printf("\nOne gives: %d\n", strend(testone, endone));
    printf("Two gives: %d\n", strend(testone, endtwo));
}

int strend(char *s, char *t)
{
    int i,j;
    for (i = 0; *t++ != '\0'; i++) ;
    for (j = 0; *s++ != '\0'; j++) ;
    if (i > j)
        return 0;
    for (; i > 0; i--)
        if (!(*(--s) == *(--t)))
            return 0;
    return 1;

}
