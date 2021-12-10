#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x[1000] = {0}, a = 0, b = 0, c = 0;
    
    srand(time(NULL));

    scanf("%d %d %d",&a,&b,&c);

    for (int i = 0; i < c; i++) 
    {
        x[i] = a + rand() % (b-a+1);
		printf("%d ",x[i]);
    }

    return 0;
}