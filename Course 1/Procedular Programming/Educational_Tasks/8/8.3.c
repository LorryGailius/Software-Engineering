#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Swap(int *num1, int *num2);

int main()
{

    return 0;
}

void Swap(int *num1, int *num2)
{
    int temp;
    temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}