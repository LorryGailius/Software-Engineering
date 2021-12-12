#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myStrlen(char *string);



int main()
{

    return 0;
}

int myStrlen(char *string)
{
    int len = 0;

    for (int i = 0; string[i] != 0; ++i) 
    {
        len++;
    }

    return(len);
}
