// Laurynas Gailius PS 2 grupe 1 pogrupis
// Stud id 554


#ifndef PRIORITY_H
#define PRIORITY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data_t
{   
    void *data;
    size_t size;
}data_t;

typedef struct node_t
{
    data_t nodeData;
    struct node_t *pNextNode;
    int priority;
}node_t;

typedef struct queue_t
{
    node_t *head;
}queue_t;

/*
@function insert 
@param Queue This is a pointer to the destination queue where the content is to be inserted, type-casted to a struct of queue_t.
@param Data This is the source of data to be inserted, type-casted to a struct of data_t.
@param Priority This is the priority of the inserted data in the queue.
@param Error This is an error code pointer, casted into an integer.
@return Inserts data into priority queue
*/
void insert(queue_t *queue, data_t data, int priority, int *error);

/*
@function qcpy
@param Destination This is a pointer to the destination queue where the content is to be copied to, type-casted to a struct of queue_t.
@param Source This is the source of data to be copied from, type-casted to a struct of queue_t.
@param Length This is the number of elements to be copied to array
@param Error This is an error code pointer, casted into an integer.
@return Copies one priority queue to another
*/
void qcpy(queue_t *destination, queue_t source, int length, int *error);

/*
@function join
@param Queue1 This is the source of data to be copied from, type-casted to a struct of queue_t.
@param Queue2 This is the source of data to be copied from, type-casted to a struct of queue_t.
@param Error This is an error code pointer, casted into an integer.
@return Returns a priority queue joined from two other priority queues
*/
queue_t join(queue_t queue1, queue_t queue2, int *error);

/*
@function get_length
@param Queue This is the list to be counted, type-casted to a struct of queue_t.
@return Returns the length of a queue as an integer. Returns 0 if given an empty queue.
*/
int get_length(queue_t queue);

/*
@function is_empty
@param Queue  This is the queue to check.
@return Checks if given queue is empty. 1 - if true, 0 - if false.
*/
int is_empty(queue_t queue);

/*
@function create_queue
@param Error This is an error code pointer, casted into an integer.
@return Returns an empty priority queue.
*/
queue_t create_queue(int *error);

/*
@function pop
@param Queue This is a pointer to the queue where the content is to be removed from, type-casted to a struct of queue_t.
@param Error This is an error code pointer, casted into an integer.
@return Returns the first element from the specified priority queue and removes it from the queue.
*/
data_t pop(queue_t *queue, int *error);

/*
@function create_queue
@param Queue This is a pointer to the queue where the content is to be returned from, type-casted to a struct of queue_t.
@param Error This is an error code pointer, casted into an integer.
@return Returns the first element from the specified priority queue without removing it.
*/
data_t get(queue_t queue, int *error);

/*
@function clear_queue
@param Queue This is a pointer to the queue where the content is to be freed from, type-casted to a struct of queue_t.
@return Deletes the priority queue
*/
void clear_queue(queue_t *queue);

/*
@function print_queue
@param Queue This is the source of data to be printed from, type-casted to a struct of queue_t.
@param Print_Function This is the function spcified for printing the specific data type of data.
@param Error This is an error code pointer, casted into an integer.
@param Priorities A boolean type integer. True - function prints element priority, False - only prints out element.
@param Stream This is the pointer to a FILE object that identifies the stream where the queue is to be written.
@return Prints out a queue to the specified FILE stream
*/
void print_queue(queue_t queue, void (*prnt_func)(const void *, FILE *), int *error, int printPriorities, FILE *fs);

/*
@function print_int
@param Value This is the value to be written, casted to a void*.
@param Stream This is the pointer to a FILE object that identifies the stream where the value is to be written.
@return Prints out an integer ( used for the function print_queue() ).
*/
void print_int(const void *a, FILE *fs);

/*
@function print_str
@param Value This is the string to be written, casted to a void*.
@param Stream This is the pointer to a FILE object that identifies the stream where the value is to be written.
@return Prints out a string ( used for the function print_queue() ).
*/
void print_str(const void *a, FILE *fs);

/*
*
*   Error Codes
*   0 - No errors occured during function
*   1 - The function was given an empty queue
*   2 - An element could not be inserted into queue
*   3 - Output/Input File stream Error
*
*/

#endif