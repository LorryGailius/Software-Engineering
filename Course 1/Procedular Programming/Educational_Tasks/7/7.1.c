#include <stdlib.h>
#include <stdio.h>

int isInRange(int number, int low, int high);

int main()
{

    return 0;
}

int isInRange(int number, int low, int high)
{
    if (low > high)
    {
        return 0;
    }
    
    if (number >= low && number <= high){
        return 1;
    }else{
        return 0;
    }
}