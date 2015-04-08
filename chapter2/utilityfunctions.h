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

int reverse(char forward[], char backward[], int len) // pictures help yo!
{
    int i;

    for (i = 0; i <= len -2; i++)
        backward[len - (i + 2)] = forward[i];
    backward[len-1] = '\n';
    backward[len] = '\0';
}


