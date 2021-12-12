#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high);

int *createArray(int size);

int main()
{

    return 0;
}

void generateArray(int *data, int size, int low, int high)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        *(data + i) = (rand() % (high - low + 1)) + low;
    }
}

int *createArray(int size)
{
    int *p = calloc(size,sizeof(int));

    if (p != NULL)
    {
        generateArray(p,size,0,50);
    }

    return p;
}