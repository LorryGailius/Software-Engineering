// Laurynas Gailius PS 2 grupe 1 pogrupis
// Stud id 554

#ifndef SPLIT_H
#define SPLIT_H

#define MAX_ARR_SIZE 65535
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
@function split
@param Array A pointer to integer array to split
@param Size Size of array
@param FileStream A pointer to a file stream to output to
@param printArray bool type of function. >0 - prints out the array; <0 - prints out only the minimum difference found
@return Divides an array into two minimal difference sub-arrays
*/
void split(int *arr, int size, FILE *os, int printArray);

void finMinDiff(int *arr, int size);

#endif