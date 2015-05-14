#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void printTwo(void);
void stackDupe(char s[]);
void stackSwap(void);
void stackClear(void);

main()
{
    int type;
    double op2; // temp var for noncommutative operations (/ -)
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                printTwo();
                stackSwap();
                printTwo();
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

#define MAXVAL 100 // max depth of val stack

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


int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ; // skip blanks
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}





















