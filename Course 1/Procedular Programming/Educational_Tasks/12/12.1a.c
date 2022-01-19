#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fill_array(int *array, int size, int low, int high);

int main()
{

    return 0;
}

void fill_array(int *array, int size, int low, int high)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % (high - low + 1)) + low;;
    }
}