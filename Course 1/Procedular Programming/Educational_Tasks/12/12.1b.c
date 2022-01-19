#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void fill_array(int *array, int size, int low, int high);

void check_sort(int *array, int size);

int main()
{

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    check_sort(arr,10);

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

void check_sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] > array[i + 1])
        {
                printf("%d !< %d", array[i], array[i + 1]);
                break;
        }
    }
}