#include <priority.h>

void insert(queue_t *queue, data_t data, int priority, int *error)
{
    *error = 2;

    node_t* temp = NULL;
    node_t* newNode = NULL;

    temp = ((*queue).head);
    newNode = (node_t*)malloc(sizeof(node_t));

    if (newNode != NULL)
    {
        newNode->data.size = data.size;
        newNode->data.data = malloc(data.size);
        memcpy(newNode->data.data, data.data, data.size);
        newNode->priority = priority;

        newNode->pNextNode = NULL;
        *error = 0;


        if(((*queue).head) == NULL)
        {
            ((*queue).head) = newNode;
        }
        else
        {
            if (temp->priority > priority)
            {
                newNode->pNextNode = ((*queue).head);
                ((*queue).head) = newNode;
            }
            else
            {
                while(temp->pNextNode != NULL && temp->pNextNode->priority < priority)
                {
                    temp = temp->pNextNode;
                }
                newNode->pNextNode = temp->pNextNode;
                temp->pNextNode = newNode;
            }
        }
    }
    return;
}

void qcpy(queue_t *destination, queue_t source, int *error)
{

    if (is_empty(source))
    {
        *error = 1;
        return;
    }
    else
    {
        node_t *temp = source.head;
        while (source.head != NULL)
        {
            insert(destination, source.head->data, source.head->priority, error);
            source.head = source.head->pNextNode;
        }
        source.head = temp;
    }
}

queue_t join(queue_t queue1, queue_t queue2, int *error)
{
    queue_t retValue;
    retValue.head = NULL;

    if (is_empty(queue1) || is_empty(queue2))
    {
        *error = 1;
    }
    else
    {
        node_t *temp1 = queue1.head;
        node_t *temp2 = queue2.head;
        while (queue1.head != NULL)
        {
            insert(&retValue, queue1.head->data, queue1.head->priority, error);
            queue1.head = queue1.head->pNextNode;
        }

        while (queue2.head != NULL)
        {
            insert(&retValue, queue2.head->data, queue2.head->priority, error);
            queue2.head = queue2.head->pNextNode;
        }
    }
    

    

}

queue_t create_queue(int *error)
{
    queue_t queue;
    queue.head = NULL;

    return queue;
}

data_t pop(queue_t *queue, int *error)
{
    data_t retValue;
    if (!is_empty(*queue))
    {
        node_t *temp = ((*queue).head);
        ((*queue).head) = ((*queue).head)->pNextNode;
        retValue.data = temp->data.data;
        free(temp->data.data);
        free(temp);
    }
    else
    {
        *error = 1;
    }
    
    return retValue;
}

data_t get(queue_t queue, int *error)
{
    data_t retValue;
    if (is_empty(queue))
    {
        *error = 1;            
    }
    
    return retValue;
}

void clear_queue(queue_t *queue)
{
    node_t* tempNode = (node_t*)malloc(sizeof(node_t));
    node_t* headNode = (node_t*)malloc(sizeof(node_t));

    headNode = (*queue).head;

    while (headNode != NULL)
    {
        tempNode = headNode;

        headNode = headNode->pNextNode;

        free(tempNode->data.data);
        free(tempNode);
    }
    
    (*queue).head = NULL;
}

void print_queue(queue_t queue, void (*prnt_func)(const void *, FILE *), int *error, FILE *fs)
{
    if (queue.head == NULL)
    {
        *error = 1;
    }
    if (fs != NULL)
    {
        fputs("",fs);
        while (queue.head)
        {
            prnt_func((queue.head)->data.data, fs);
            queue.head = (queue.head)->pNextNode;
        }
    }
    else
    {
        *error = 3;
    }

    fputs("\n", fs);
    if (fs != stdout)
    {
        fclose(fs);
    }
}


void print_int(const void *a, FILE *fs)
{
    fprintf(fs, "%d", *(int*)a);
    fputs("\n", fs);
}

int is_empty(queue_t queue)
{
    if (queue.head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}