#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};

typedef struct Point Point;

void printPoint(Point Point);

Point createPoint(double x, double y);

double getDistance(Point a, Point b);

int main()
{
    printf("%.3f", getDistance(createPoint(2, -3), createPoint(-4, 5)));

    return 0;
}

Point createPoint(double x, double y)
{
    Point point;
    point.x = x;
    point.y = y;

    return point;
}

void printPoint(struct Point p)
{
    printf("(%.2f,%.2f)\n",p.x,p.y);
}

double getDistance(Point a, Point b)
{
    double dist;

    dist = sqrt(pow( (a.x - b.x), 2) + pow( (a.y - b.y), 2));

    return dist;
}