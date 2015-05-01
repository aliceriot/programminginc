int mygetline(char s[], int lim) // this was slightly changed for ch 4
{
    int c,i;
    i = 0;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
        s[i++] = c;
    if (c == '\n') {
        s[i++] = c;
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
        if (s1[i] != s2[i])
            return 0;
        }
    return 1;
}

int stringAppend(char s[], char insert[], int pos)
{
    int i;

    for (i = 0; insert[i] != '\0'; i++)
        s[i+pos] = insert[i];
    return i-1;
}


