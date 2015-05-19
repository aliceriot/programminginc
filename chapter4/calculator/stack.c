#include <stdio.h>
#include "calc.h"

#define MAXVAK 100

int sp = 0;
double val[MAXVAL];

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
