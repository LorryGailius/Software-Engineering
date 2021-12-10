#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s, n, val = 0;
    
    scanf("%d %d",&s,&n);

    int *array = calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &array[i]);
        do
        {
            if (array[i] < 0)
            {
                printf("Enter a non negative number!\n");
                while(getchar() != '\n')
                ;

                scanf("%d", &array[i]);
            }
        } while (array[i] < 0);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int mul = (array[i] * array[j]);
            if (mul == s)
            {
                printf("%d - %d | %d\n", array[i], array[j], mul);
                ++val;
            }
        }
    }

    if (val == 0)
    {
        printf("There are no values equal to %d\n", s);
    }
    

    return 0;
}