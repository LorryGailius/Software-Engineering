#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>

typedef struct node_t {
    void *data;
    struct node_t *next;
} node_t;

typedef struct queue_t {
    struct node_t *head;
    struct node_t *tail;
    size_t elem_cnt;
} queue_t;

/// Creates a queue
/// @return queue object
queue_t create_queue();

/// Adds an element to the queue
/// @param q pointer to queue object
/// @param data data you want to store
/// @param size size of data in bytes
/// @return nothing
void enqueue(queue_t *q, void *data, size_t size);

/// Removes an element from the queue
/// Note: memory returned by dequeue needs to be freed manually
/// @param q pointer to queue object
/// @return pointer to the element
void* dequeue(queue_t *q);

/// Frees elements contained by queue
/// @param q pointer to queue object
/// @return nothing
void free_queue(queue_t *q);

#endif