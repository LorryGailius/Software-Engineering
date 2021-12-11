#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};
 
typedef struct Point Point;

struct Stack
{
    Point *arr;
    int size;
};

typedef struct Stack Stack;

void initStack(Stack *stack);

void printStack(Stack *stack);

int getStackSize(Stack *stack);

void printPoint(Point Point);
 
Point createPoint(double x, double y);
 
double getDistance(Point a, Point b);

int randomNumber(int low, int high);

int main()
{
    srand(time(NULL));

    //Send &Stack when calling func
    Stack st;

    st.size = 5;

    initStack(&st);
    printStack(&st);

    return 0;
}

void initStack(Stack *stack)
{
    stack -> arr = calloc(stack -> size, sizeof(Point));

    for (int  i = 0; i < stack -> size; ++i)
    {
        stack -> arr[i] = createPoint(randomNumber(-10,10),randomNumber(-10,10));
    }
}

void printStack(Stack *stack)
{
    Point zero = createPoint(0,0);

    puts("Array: ");

    for (int i = 0; i < stack -> size; ++i)
    {
        printPoint(stack -> arr[i]);
    }

    puts(" ");

    puts("Distance from (0,0):");

    for (int i = 0; i < stack -> size; ++i)
    {
        printf("%.3f ", getDistance(stack->arr[i], zero));
    }
    
    puts(" ");
}

int getStackSize(Stack *stack)
{
    return stack -> size;
}

Point createPoint(double x, double y)
{
    Point point;
    point.x = x;
    point.y = y;
 
    return point;
}
 
void printPoint(Point p)
{
    printf("(%.2f,%.2f) ",p.x,p.y);
}
 
double getDistance(Point a, Point b)
{
    double dist;

    dist = sqrt(pow( (a.x - b.x), 2) + pow( (a.y - b.y), 2));
 
    return dist;
}

int randomNumber(int low, int high)
{
    int num = 0;

    num = (rand() % (high - low + 1)) + low;

    return num;
}