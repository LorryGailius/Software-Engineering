#include <priority.h>

void node_insert(node_t **head, void *data, size_t size, int priority, int *error)
{
    *error = 3;

    node_t* temp = NULL;
    node_t* newNode = NULL;

    temp = (*head);
    newNode = (node_t*)malloc(sizeof(node_t));

    if (newNode != NULL)
    {
        newNode->data = malloc(size);
        memcpy(newNode->data, data, size);
        newNode->priority = priority;

        newNode->pNextNode = NULL;
        *error = 0;
    }
    
    if((*head) == NULL)
    {
        (*head) = newNode;
    }
    else
    {
        if (temp->priority > priority)
        {
            newNode->pNextNode = (*head);
            (*head) = newNode;
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
    return;
}

node_t *create_queue(int *error)
{
    node_t *q = calloc(1, sizeof(node_t));

    *error = (q != NULL);
}

void pop(node_t **head)
{
    node_t *temp = (*head);
    (*head) = (*head)->pNextNode;
    free(temp->data);
    free(temp);
}

void clear_queue(node_t **head)
{
    node_t* tempNode = (node_t*)malloc(sizeof(node_t));
    node_t* headNode = (node_t*)malloc(sizeof(node_t));

    headNode = *head;

    while (headNode != NULL)
    {
        tempNode = headNode;

        headNode = headNode->pNextNode;

        free(tempNode->data);
        free(tempNode);
    }
    
    *head = NULL;
}

// Prints out all nodes, using a function specified in call
void print_queue(node_t *head, void (*prnt_func)(const void *, FILE *), FILE *fs)
{
    if (head == NULL)
    {
        puts("Error: List is empty\n");
    }
    if (fs != NULL)
    {
        fputs("",fs);
        while (head)
        {
            prnt_func(head->data, fs);
            head = head->pNextNode;
        }
    }
    else
    {
        perror("File Error");
    }

    fputs("\n", fs);
    if (fs != stdout)
    {
        fclose(fs);
    }
}

// Used for print_queue() if the list consists of integers only
void print_int(const void *a, FILE *fs)
{
    fprintf(fs, "%d", *(int*)a);
    fprintf(fs, "\n");
}