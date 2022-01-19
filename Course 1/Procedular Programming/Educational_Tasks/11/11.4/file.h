#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>

extern int loadCount;

extern int saveCount;

void loadFromFile(int *array, int *size, FILE *input);

void saveToFile(int *array, FILE *output, int size);



#endif