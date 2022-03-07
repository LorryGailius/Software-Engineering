#include <split.h>

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        int size = 0;

        FILE *is = fopen(argv[1], "r");

        if (is != NULL)
        {
            fscanf(is, "%d", &size);
            int *arr = calloc(size, sizeof(int));
            for (size_t i = 0; i < size; i++)
            {
                fscanf(is, "%d ", &arr[i]);
            }
            
            get_variations(3, 4);
        }
    }
    else
    {
        puts("No data file given!");
    }


    return 0;
}