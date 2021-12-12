#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int splitData(int arr[], int size, int size1, int **arr1,int **arr2);

int main()
{

    return 0;
}

int splitData(int arr[], int size, int size1, int **arr1, int **arr2)
{
    int valid, sizeDiff = size - size1;

    valid = (size > 0) && (size1 > 0) && (sizeDiff > 0);

    valid = valid && (*arr1 == NULL) && (*arr2 == NULL);
    
    if (valid)
    {
        (*arr1) = calloc(size1, sizeof(int));
        (*arr2) = calloc(sizeDiff, sizeof(int));
    }

    valid = valid && (*arr1 != NULL) && (*arr2 != NULL);
    
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