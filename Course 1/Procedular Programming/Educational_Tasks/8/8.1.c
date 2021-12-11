#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high);

int *createArray(int size);

int main()
{
    int n;

    scanf("%d",&n);

    createArray(n);

    return 0;
}

void generateArray(int *data, int size, int low, int high)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        *(data + i) = (rand() % (high - low + 1)) + low;
        printf("%d ",*(data + i));
    }
    printf("\n");
}

int *createArray(int size)
{
    int *p = calloc(size,sizeof(int));

    generateArray(p,size,10,20);
    
    return p;
}