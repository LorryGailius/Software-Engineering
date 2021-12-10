#include <stdio.h>
#include <stdlib.h>

int isPrime(int num);
void removeDup(int array[], int size);

int main()
{
    int size = 0, a;
    int *array = calloc(2, sizeof(int));

    do
    {
        scanf("%d", &a);
        if (a > 0)
        {
            realloc(array, (size + 1) * sizeof(int));
            array[size] = a;
            ++size;
        }
    } while (a > 0);

    removeDup(array, size);

    printf("Prime numbers are:\n");
    for (int i = 0; i < size; ++i)
    {
        if (isPrime(array[i]))
        {
            printf("%d\n", array[i]);
        }
    }

    return 0;
}

void removeDup(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (array[i] == array[j] && array[i] != -1)
            {
                array[j] = -9898;
            }
        }
    }
}

int isPrime(int num)
{
    if (num == -9898)
    {
        return 0;
    }
    

    for(int i = 2; (i * i) <= num; ++i) // Check if entered number is PRIME
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}