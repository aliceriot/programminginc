#include <stdio.h>

// print the number n in decimal!

void printd(int n);

main()
{
    printd(-234);
    printf("\n");
}

void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}
