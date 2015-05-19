#include <stdio.h>
#include "calc.h"

void printTwo(void) // execise 4-4
{
    int top = sp - 1;
    int next = sp - 2;

    if (sp > 1)
        printf("Top element: %f, next element: %f\n",val[top], val[next]);
    else
        printf("err empty stack\n");
}

void stackDupe(char dest[])
{
    int i;

    for (i=0; i < sp; i++)
        dest[i] = val[i];
}

void stackSwap(void)
{
    int tmp;

    if (sp > 1) {
        tmp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = tmp;
    }
    else
        printf("swap error, stack too small!\n");
}
    
void stackClear(void)
{
    for (sp; sp >= 0; sp--)
        val[sp] = 0.0;
}


