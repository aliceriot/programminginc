#include <ctype.h>
#include <math.h>

// remember you need to gcc -lm when you're using math.h!
// otherwise none of the math functions will work!
// it seems like this is something the compiler could warn about!
// but it doesn't!

double atof(char s[])
{
    double val, power, prefix;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e') {
        prefix = sign * val / power; // this is the number we're multiplying by 10^x
        i++;
        sign = (s[i] == '-') ? -1 : 1; // get sign of exponent
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (val = 0.0; isdigit(s[i]); i++){ // get value of exponent
            val = 10.0 * val + (s[i] - '0');
        }
        return prefix * (sign * pow(10,val));
    }
    else {
        return sign * val / power;
    }
}

// this is extended from the version presented in the book to handle
// scientific notation (e.g. 2.45e11 and so on)
