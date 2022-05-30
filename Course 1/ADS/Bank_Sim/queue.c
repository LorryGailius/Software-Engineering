#include <queue.h>

node_t* create_node(void *data, size_t size) {
    assert(data);
    assert(size > 0);

    node_t *node = (node_t*) malloc(sizeof(node_t));
    assert(node);

    node->data = malloc(size);
    assert(node->data);

    memcpy(node->data, data, size);
    node->next = NULL;

    return node;
}

void free_node(node_t *node) {
    free(node->data);
    free(node);
}

queue_t create_queue() {
    queue_t q = {NULL, NULL, 0};
    return q;
}

void enqueue(queue_t *q, void *data, size_t size) {
    assert(q);
    node_t *node = create_node(data, size);
    if(!q->head && !q->tail) {
        // Set head if this is the first node
        q->head = node; 
    } else {
        // Add node to tail
        q->tail->next = node;
    }
    // Set new tail
    q->tail = node;
    q->elem_cnt++;
}

void* dequeue(queue_t *q) {
    assert(q);
    if(q->elem_cnt == 0) return NULL;
    // Save head fields
    void *data = q->head->data;
    node_t *next = q->head->next;
    free(q->head);
    // Change tail if this was the last node
    if(q->head == q->tail) q->tail = NULL; 
    q->head = next;
    q->elem_cnt--;
    return data;
}

void free_queue(queue_t *q) {
    assert(q);
    if(q->elem_cnt == 0) return;
    node_t *it = q->head;
    while(it) {
        node_t *temp = it;
        it = it->next;
        free(temp);
    }
}