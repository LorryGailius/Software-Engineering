#include <priority.h>




int main()
{
    node_t *head = NULL;
    int error;

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;

    node_insert(&head, &a, sizeof(int), 1, &error);
    node_insert(&head, &b, sizeof(int), 2, &error);
    node_insert(&head, &c, sizeof(int), 3, &error);
    node_insert(&head, &d, sizeof(int), 0, &error);
    node_insert(&head, &e, sizeof(int), 5, &error);

    print_queue(head, print_int, stdout);


    return 0;
}