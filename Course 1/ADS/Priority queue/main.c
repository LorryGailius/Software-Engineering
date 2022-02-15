#include <priority.h>
#include <assert.h>
int main()
{
    data_t data;
    data.size = sizeof(int);
    
    int error;

    queue_t queue1 = create_queue(&error);
    queue_t queue2 = create_queue(&error);

    int a = 10;
    int b = 50;
    int c = 60;
    int d = 90;
    int e = 10;

    data.data = &a;
    insert(&queue1, data, 1, &error);
    data.data = &b;
    insert(&queue1, data, 3, &error);
    data.data = &c;
    insert(&queue1, data, 2, &error);

    printf("Queue 1: \n");
    print_queue(queue1, print_int, &error, 1, stdout);

    qcpy(&queue2, queue1, &error);

    printf("Queue 2 copied over: \n");
    print_queue(queue2, print_int, &error, 1, stdout);

    clear_queue(&queue1);

    data.data = &d;
    insert(&queue1, data, 2, &error);
    data.data = &e;
    insert(&queue1, data, 5, &error);

    printf("Queue 1 inserted: \n");
    print_queue(queue1, print_int, &error, 1,stdout);

    queue_t queue3 = join(queue1, queue2, &error);

    printf("Queue 3 joined: \n");
    print_queue(queue3, print_int, &error, 1, stdout);

    clear_queue(&queue1);
    clear_queue(&queue2);
    clear_queue(&queue3);

    return 0;
}