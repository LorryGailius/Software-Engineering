#include <stdlib.h>
#include <stdio.h>

struct Stack
{
    int* arr;
    int size;
};

typedef struct Stack Stack;

void initStack(Stack *stack);

void printStack(Stack *stack);

int getStackSize(Stack *stack);

int main()
{
    //Send &Stack when calling func

    return 0;
}

void initStack(Stack *stack)
{

    stack -> arr = calloc(stack -> size,sizeof(int));

}

void printStack(Stack *stack)
{

    puts("Array: ");

    for (int i = 0; i < stack -> size; ++i)
    {
        printf("%d ", stack -> arr[i]);
    }

    puts(" ");

}

int getStackSize(Stack *stack)
{

    return stack -> size;

}