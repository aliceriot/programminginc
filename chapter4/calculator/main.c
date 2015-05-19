#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

main()
{
    int type;
    double op2; // temp var for noncommutative operations (/ -)
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: div0\n");
                break;
            case '%': // exercise 4-3
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case '^':
                op2 = pop();
                push(pow(op2,pop()));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
