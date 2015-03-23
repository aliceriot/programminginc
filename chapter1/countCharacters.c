#include <stdio.h>

// a variation on our copy program!

main()
{
    //ahh, initially I used a double, and adding an integer
    //below screwed things up

    long count = 0;
    int c;

    while ((c = getchar()) != EOF){
        putchar(c);
        ++count;
    }

    printf("We copied %d characters!\n", count);
}


