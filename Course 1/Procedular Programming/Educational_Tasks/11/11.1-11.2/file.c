#include <file.h>

int saveCount = 0;
int loadCount = 0;

void saveToFile(int *array, FILE *output, int size)
{
    fwrite(&size, sizeof(int), 1, output);
    fwrite(array, sizeof(int), size, output);
    saveCount++;
};

void loadFromFile(int *array, int *size, FILE *input)
{
    fread(size, sizeof(int), 1, input);
    fread(array, sizeof(int), *size, input);
    loadCount++;
};