#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void printArray(int v[], int len);

void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    printArray(v, right);
    last = left;
    for (i = left+1; i <= right; i++)
        if (v[i] < v[left]) {
            swap(v, ++last, i);
            printArray(v, right);
        }
    swap(v, left, last);
    printArray(v, right);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
    printArray(v, right);
}

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// this is a nice function which lets us print out the current state of the 
// array, it's fun to watch it evolve as it gets sorted! Also lets us peek at how many 
// 'swap' operations happen for a given array
void printArray(int v[], int len)
{
    int i;

    for (i = 0; i <= len; i++)
        putchar(v[i] + '0');
    printf("\n");
}

main()
{
    int myarray1[] = {8,6,2,3,1,2,5,9};
    int myarray2[] = {8,6,2,3,1,8,56,5,6,5,3,2,34,5,4,45,5,5,45,4,2,34,93,4,5,45,39};

    qsort(myarray1, 0, 7);

    printf("\nThat was array 1! \n");

    qsort(myarray2, 0, 26);

    printf("blecch!\n");
}


