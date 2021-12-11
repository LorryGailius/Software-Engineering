#include <stdlib.h>
#include <stdio.h>

int getPositiveNumber(char *msg);

int main()
{

    return 0;
}

int getPositiveNumber(char *msg)
{
    int valid,num;
    printf("%s",msg);
    do
    {

        valid = scanf("%d",&num) == 1 && (getchar() == '\n') && (num > 0);

        if(!valid)
        {
            printf("%s",msg);
            scanf("%*[^\n]");
        }

    } while (!valid);
    
    return num;
}