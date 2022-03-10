// Laurynas Gailius PS 2 grupe 1 pogrupis
// Stud id 554

#ifndef PARTITION_H
#define PARTITION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>

void partition_array(int *array, size_t n, int **array1, size_t * n1, int **array2, size_t * n2);

void print_array(const int *array, size_t n, FILE *os);

int get_array_sum(const int *array, size_t n);

#endif