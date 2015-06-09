#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define BUFSIZE 50000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char storageBuffer[]);
void writelines(char *lineptr[], int nlines);
int mygetline(char *, int);
char *alloc(int);
void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;

    char storageBuffer[BUFSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, storageBuffer)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big!\n");
        return 1;
    }
}

#define MAXLEN 1000


int readlines(char *lineptr[], int maxlines, char storageBuffer[])
{
    int len, nlines;
    char *p, line[MAXLEN];
    p = storageBuffer;

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p >= storageBuffer + BUFSIZE)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

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

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <=right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
