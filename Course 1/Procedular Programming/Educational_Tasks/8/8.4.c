#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int splitData(int arr[], int size, int size1, int **arr1,int **arr2);

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}, size = 10, size1 = 4;
    int *r1,*r2;

    splitData(arr,size,size1,&r1,&r2);

    for (int i = 0; i < size1; i++)
    {
        printf("%d ",r1[i]);
    }
    printf("\n");
    for (int i = 0; i < size-size1; i++)
    {
        printf("%d ",r2[i]);
    }
    
    free(r1);
    free(r2);

    return 0;
}

int splitData(int arr[], int size, int size1, int **arr1, int **arr2)
{
    int valid, sizeDiff = size - size1;

    valid = (size > 0) && (size1 > 0);
    
    if (valid)
    {
        (*arr1) = calloc(size1, sizeof(int));
        (*arr2) = calloc(sizeDiff, sizeof(int));
    }

    valid = valid && (*arr1) && *arr2;
    
    if (valid)
    {
        for (int i = 0; i < size1; i++)
        {
            (*arr1)[i] = arr[i];
        }

        for (int i = 0; i < sizeDiff; i++)
        {
            (*arr2)[i] = arr[i+size1];
        }
        return 0;
    }
    else
    {
        return -1;
    }
}