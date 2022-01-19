#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef  void (*sort_func_t)(int *, int);

void fill_array(int *array, int size, int low, int high);

void print_array(int *array, int size);

void check_sort(int maxSize, sort_func_t func);

void swap(int * a, int * b);

void bubble_sort(int *array, int size);

void quick_sort (int * const array, int num);

void _quick_sort(int * const array, int start, int end);

int qs_partition(int * const array, int start, int end); 

void insertion_sort(int *array, int size);

void selection_sort(int *array, int size);

void merge_sort_(int *array, int size);

void merge_sort(int *array, int l, int r);

void merge(int *array, int l, int m, int r);

#endif