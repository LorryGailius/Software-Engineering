#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;

    scanf("%d",&number);

    printf("Skaicius %d yra %s",number,((number % 2) ? "nelyginis" : "lyginis"));


    return 0;
}
