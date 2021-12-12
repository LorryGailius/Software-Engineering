#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *mystrchr(char *string, int ch);

int main()
{

    return 0;
}

char *mystrchr(char *string, int ch)
{   
    char *ret = NULL;
    for (int i = 0; i < strlen(string) + 1; ++i)
    {
        if (string[i] == ch)
        {
            ret = &string[i];
            break;
        }
    }

    return ret;
}