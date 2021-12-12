#include <stdlib.h>
#include <stdio.h>

int getFactorialRec(int number);
int getFactorial(int number);

int main()
{
    printf("recursive - %d\n", getFactorialRec(0));
    printf("non recursive - %d\n", getFactorial(0));

    return 0;
}

int getFactorialRec(int number)
{
    if (number >= 0 && number <= 12)
    {
        if(number >= 1)
        {
            return getFactorialRec(number-1) * number;
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

int getFactorial(int number)
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