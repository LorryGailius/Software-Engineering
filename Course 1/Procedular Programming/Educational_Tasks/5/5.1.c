#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        printf(" %d ",a[i]);
    }
    
    printf("\n");

    a[0] = 1, a[3] = 2,a[9] = 3;

    for (int i = 2; i <= 9; i++)
    {
        a[i] = (i == 9) ? 0 : a[i+1];
    }

    for (int i = 9; i >= 6; --i)
    {
        a[i] = (i == 6) ? 4 : a[i-1];
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ",a[i]);
    }
    
    printf("\n");

    int x = 0, y = 0;

    scanf("%d %d", &x, &y);

    a[x-1] = y;

    scanf("%d", &x);

    for (int i = x-1; i <= 9; i++)
    {
        a[i] = (i == 9) ? 0 : a[i+1];
    }

    scanf("%d %d",&x,&y);

    for (int i = 9; i >= x; --i)
    {
        a[i] = (i == (x)) ? y : a[i-1];
    }

    for (int i = 0; i < 10; i++)
    {
        printf(" %d ",a[i]);
    }

    return 0;
}