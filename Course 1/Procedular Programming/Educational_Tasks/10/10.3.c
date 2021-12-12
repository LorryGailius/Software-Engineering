#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *mystrncpy(char *destination, const char *source, size_t count);

int main()
{

    return 0;
}

char *mystrncpy(char *destination, const char *source, size_t count)
{
    if (count <= strlen(source))
    {
        for (size_t i = 0; i < count; ++i)
        {
            destination[i] = source[i];
        }
    }
    else
    {
        for (size_t i = 0; i < strlen(source); ++i)
        {
            destination[i] = source[i];
        }

        for (size_t i = strlen(source); i < count; ++i)
        {
            destination[i] = '\0';
        }
        
    }

    return destination;
}