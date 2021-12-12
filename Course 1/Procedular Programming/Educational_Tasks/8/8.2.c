#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long getFileSize(char *fileName);

char* Sort(int argc, char **argv);

int main(int argc, char **argv)
{
    Sort(argc, argv);
    return 0;
}

char* Sort(int argc, char **argv)
{
    char *name = calloc(256, sizeof(char));
    if(argc == 1)
    {
        printf("No file names given\n");
    }
    else
    { 
        for (int i = 1; i <= argc-1; i++)
        {
            long long size = getFileSize(argv[i]), max = 0;
            if (max < size)
            {
                strcpy(name, argv[i]);
                max = size;
            }
        }
    }
    return name;
}

long long getFileSize(char *fileName)
{
    FILE *file;
 
    if(file = fopen(fileName, "rb"))
    {
        fseek(file, 0, SEEK_END);
 
        return ftell(file);
    }
    else
    {
        return -1;
    }
}