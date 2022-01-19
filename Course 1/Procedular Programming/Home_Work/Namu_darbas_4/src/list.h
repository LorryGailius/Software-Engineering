#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node_t
{
    void *data;
    struct node_t *pNextNode;
}node_t;

int node_pushf(node_t** head, void * data, size_t size);

int node_pushb(node_t** head, void * data, size_t size);

void clear_list(node_t** head);

void print_list(node_t* head, void (*prnt_func)(const void *, FILE *), FILE * fs);

int node_insert(node_t** head, void * data, size_t size, void * insert, int (*cmp_func)(const void *, const void *, size_t));

void print_int(const void *a, FILE * fs);

#endif