#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *myStrcpy(char *destination, const char *source);

int main()
{

    return 0;
}

char *myStrcpy(char *destination, const char *source)
{
        for (int i = 0; i < strlen(source) + 1; ++i)
        {
            destination[i] = source[i];
        }

        return destination;
}