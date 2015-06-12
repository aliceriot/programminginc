#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (day > daytab[leap][month])
        return -1;

    for (i = 0; i < month; i++)
        day += daytab[leap][i];
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if (yearday > 366)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    return 0;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

void main()
{
    printf("March 14th is day %d!\n", day_of_year(2015, 3, 14));
    int month, day;
    int *pmonth = &month;
    int *pday = &day;
    month_day(2010, 246, pmonth, pday);
    printf("The 246th day of 2012 is %d/%d/12!\n", *pmonth, *pday);
}

/*     Ok, so this tells us some interesting and useful things about */ 
/*     pointers! If we just declare a pointer int *p we can't assign */
/*     things to it yet (other than addresses). In other words, we */ 
/*     can't yet do something like *p = 123, since the pointer does */
/*     not yet have the address of an actual int stored in it there is */ 
/*     nothing (but potentially garbage) to dereference it to. Neat! */
