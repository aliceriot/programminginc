#include <stdio.h>
#include <string.h>
#include "utility.h"

#define MAXLINE 1000

void expand(char s1[], char s2[]);

main()
{
    char smallstring[MAXLINE] = "we have 1-9 abc a-z stuff";
    char bigstring[MAXLINE];
    char tempstring[3];
    int x;

    expand(smallstring,bigstring);

    printf("%s\n%s\n",smallstring,bigstring);

}

void expand(char s1[], char s2[])
{
    int i, s1offset, s2offset, j, temp;
    s1offset = s2offset = 0;

    char tempstring[3];

    // replacement strings
    char abc[26] = "abcdefghijklmnopqrstuvwxyz";
    char zeronine[23] = "testing the poop waters";

    // test strings
    char abc1[3] = "a-z";
    char abc2[3] = "A-Z";
    char abc3[3] = "abc";
    char abc4[3] = "ABC";
    char ninetest[3] = "1-9";
    
    for (i = 0;(i+s1offset) < strlen(s1); i++) {
        for (j = 0; j < 3; j++)
            tempstring[j] = s1[i+s1offset+j];
        if (stringeq(tempstring,abc1)) {
            temp = stringAppend(s2,abc,i+s2offset);
            s2offset += temp;
            s1offset += 2;
        }
        else if (stringeq(tempstring,abc2)) {
            temp = stringAppend(s2,abc,i+s2offset);
            s2offset += temp;
            s1offset += 2;
        }
        else if (stringeq(tempstring,abc3)) {
            temp = stringAppend(s2,abc,i+s2offset);
            s2offset += temp;
            s1offset += 2;
        }
        else if (stringeq(tempstring,abc4)) {
            temp = stringAppend(s2,abc,i+s2offset);
            s2offset += temp;
            s1offset += 2;
        }
        else if (stringeq(tempstring,ninetest)) {
            temp = stringAppend(s2,zeronine,i+s2offset);
            s2offset += temp;
            s1offset += 2;
        }
        else if (s1[i+s1offset] == '\0')
            s2[i+s2offset] = '\0';
        else
            s2[i+s2offset] = s1[i+s1offset];
    }
}







