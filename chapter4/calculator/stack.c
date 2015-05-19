#include <stdio.h>
#include "calc.h"


static int sp = 0;
static double val[MAXVAL];

void push(double f) // takes a double, pushes it onto the stack
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

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


