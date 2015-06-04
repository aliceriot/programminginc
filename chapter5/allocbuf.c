#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp -n;
    } else 
        return NULL;
}

void afree(char *p)
{
    // this lets us free memory by moving allocp to any place we want
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
