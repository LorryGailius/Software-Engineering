#include <stdlib.h>
#include <stdio.h>

int getFactorial(int number);
int getFactorial2(int number);

int main()
{
    printf("recursive - %d\n", getFactorial(10));
    printf("non recursive - %d\n", getFactorial2(10));

    return 0;
}

int getFactorial(int number)
{
    if (number >= 0 && number <= 12)
    {
        if(number >= 1)
        {
            return getFactorial(number-1) * number;
        }
        else
        {
            return 1;
        } 
    }
    else
    {
        return 0;
    }
}

int getFactorial2(int number)
{
    int ans = 1;

    if (number <= 12 && number >= 0)
    {
        for (int i = 0; i < number; i++)
        {
            ans += ans * i;
        }
        return ans;
    }
    else
    {
        return 0;    
    }
}