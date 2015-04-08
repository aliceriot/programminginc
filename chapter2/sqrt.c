#include <stdio.h>
#include <ctype.h>
#include <math.h>

double sqrt(double);

main()
{
    int c;
    c = getchar() - '0';

    printf("The sqrt of %d is %f\n", c, sqrt(c));
}

// it works! sometimes you have to do strange things to get stuff to work...
// so the K&R is a little behind the GNU C lib, I guess? It seems the the library
// has added some nice functionality that the book/C89 standard doesn't specify, 
// like automatic typecasting on the sqrt function (you can pass it an int and it
// does just fine with it)
