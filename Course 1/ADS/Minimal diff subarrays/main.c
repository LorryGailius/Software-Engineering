#include <split.h>

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        int *arr = calloc(MAX_ARR_SIZE, sizeof(int));
        int size = 0;

        FILE *is = fopen(argv[1], "r");

        if (is != NULL)
        {
            while (size <= MAX_ARR_SIZE && !feof(is))
            {
                fscanf(is, "%d ", &arr[size]);
                size++;
            }
            
            finMinDiff(arr,size);
        }
    }
    else
    {
        puts("No data file given!");
    }


    return 0;
}