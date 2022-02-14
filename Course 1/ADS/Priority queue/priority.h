#ifndef PRIORITY_H
#define PRIORITY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node_t
{
    void *data;
    struct node_t *pNextNode;
    int priority;
}node_t;

void node_insert(node_t **head, void *data, size_t size, int priority, int *error);

node_t *create_queue(int *error);

void pop(node_t **head);

void clear_queue(node_t **head);

void print_queue(node_t *head, void (*prnt_func)(const void *, FILE *), FILE *fs);

void print_int(const void *a, FILE *fs);

#endif