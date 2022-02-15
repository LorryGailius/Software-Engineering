#include <list.h>

// Insert node to the left of specified value
int node_insert(node_t** head, void * data, int size, void * insert, int (*cmp_func)(const void *, const void *, int))
{
    int retValue = 0;
	
    if (*head == NULL)
    {
        return retValue;
    }
    
    node_t* newNode = (node_t*)malloc(sizeof(node_t));

    node_t* tempNode = (*head);

    if (newNode != NULL)
    {
        // Add the data to new node
        newNode->data = malloc(size);
        memcpy(newNode->data, insert, size);
    }
    
    // Compare the head of the list
    if (cmp_func((*head)->data, data, size) == 0)
    {
        newNode->pNextNode = (*head);
        (*head) = newNode;
        retValue = 1;
    }
    else
    {
        // Compare every other node
        node_t *preNode = NULL; // Used to save previous node for insertion
        
        while (tempNode != NULL)
        {
            if(cmp_func(tempNode->data, data, size) == 0)
            {
                newNode->pNextNode = tempNode;
                preNode->pNextNode = newNode;
                retValue = 1;
                break;
            }
            // Move forward to the list
            preNode = tempNode;
            tempNode = tempNode->pNextNode;
        }
    }

    if(!retValue)
    {
        free(newNode->data);
        free(newNode);
    }

    return retValue;
}

// Insert node to the front of the list
int node_pushf(node_t** head, void * data, int size)
{
    int retValue = 0;
    
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode != NULL)
    {
        // Add the data to new node
        newNode->data = malloc(size);
        memcpy(newNode->data, data, size);
        // Make the new node the head
        newNode->pNextNode = (*head);
        (*head) = newNode; 

        retValue = 1;
    }

    return retValue;
}

// Insert node to back of the list
int node_pushb(node_t** head, void * data, int size)
{
    int retValue = 0;

    node_t* preNode = NULL;
    node_t* newNode = NULL;

    preNode = (*head);
    newNode = (node_t*)malloc(sizeof(node_t));

    if (newNode != NULL)
    {
        newNode->data = malloc(size);
        memcpy(newNode->data, data, size);

        newNode->pNextNode = NULL;
        retValue = 1;
    }
    
    if(preNode == NULL)
    {
        (*head) = newNode;
    }
    else
    {
        while(preNode->pNextNode != NULL)
        {
            preNode = preNode->pNextNode;
        }
        preNode->pNextNode = newNode;
    }

    return retValue;
}

void clear_list(node_t** head)
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
void print_list(node_t* head, void (*prnt_func)(const void *, FILE *), FILE *fs)
{
    if (head == NULL)
    {
        puts("List is empty\n");
        if (fs != stdout)
        {
            fclose(fs);
        }
        return;
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

// Used for print_list() if the list consists of integers only
void print_int(const void *a, FILE * fs)
{
    fprintf(fs, "%d ", *(int*)a);
    fprintf(fs, "\n");
}