int mygetline(char s[], int lim)
{
    int c,i;

    for (i=0; (c=getchar()) != EOF && c!='\n' && i < lim -1; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int reverse(char s[])
{
    int c,i,j;

    for (i = 0, j = strlen(s)-1; i < j; i++,j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int stringeq(char s1[], char s2[])
{
    int i;

    for (i = 0; i < strlen(s1); i++) {
        if (s1[i] == s2[i])
            break;
        else if (s1[i] == '\0') {
            return 0;
        }
    }
    return 1;
}
