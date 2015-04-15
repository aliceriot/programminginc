#include <stdio.h>

int binsearch(int x, int v[], int n);

main()
{
    int v[100];
    int i;

    for (i = 0; i < 100; i++) {
        v[i] = i * 2;
    }

    printf("The location of 10 is %d\n",binsearch(10,v,100));
}

// 
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high - mid-1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
