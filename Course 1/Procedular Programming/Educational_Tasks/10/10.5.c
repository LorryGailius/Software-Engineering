#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void *mymemcpy(void * dest, const void * src, size_t count);

int main()
{

   return 0;
}

void *mymemcpy(void * dest, const void * src, size_t count)
{
    // Convert to char, because sizeof(char) < sizeof(int)
    char *isrc = (char *)src;
    char *idest = (char *)dest;

    for (size_t i = 0; i < count; ++i)
    {
        idest[i] = isrc[i];
    }
    
}