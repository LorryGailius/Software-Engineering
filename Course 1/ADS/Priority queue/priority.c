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
        newNode->nodeData.size = data.size;
        newNode->nodeData.data = malloc(data.size);
        memcpy(newNode->nodeData.data, data.data, data.size);
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

void qcpy(queue_t *destination, queue_t source, int length, int *error)
{

    if (is_empty(source))
    {
        *error = 1;
        return;
    }
    else
    {
        for (size_t i = 0; i < length; i++)
        {
            if (source.head != NULL)
            {
                insert(destination, source.head->nodeData, source.head->priority, error);
                source.head = source.head->pNextNode;
            }
        }
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
        while (queue1.head != NULL)
        {
            insert(&retValue, queue1.head->nodeData, queue1.head->priority, error);
            queue1.head = queue1.head->pNextNode;
        }

        while (queue2.head != NULL)
        {
            insert(&retValue, queue2.head->nodeData, queue2.head->priority, error);
            queue2.head = queue2.head->pNextNode;
        }
    }
    return retValue;
}

int get_length(queue_t queue)
{
    if (queue.head == NULL)
    {
        return 0;
    }
    else
    {
        int retValue = 0;
        while (queue.head != NULL)
        {
            retValue++;
            queue.head = queue.head->pNextNode;
        }
        return retValue;
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
        retValue.data = temp->nodeData.data;
        free(temp->nodeData.data);
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

        free(tempNode->nodeData.data);
        free(tempNode);
    }
    
    (*queue).head = NULL;
}

void print_queue(queue_t queue, void (*prnt_func)(const void *, FILE *), int *error, int printPriorities, FILE *fs)
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
            if(printPriorities) { fprintf(fs, "Priority : %d | ", queue.head->priority); }
            prnt_func((queue.head)->nodeData.data, fs);
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

void print_str(const void *a, FILE *fs)
{
    fprintf(fs, "%s", (char*)a);
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