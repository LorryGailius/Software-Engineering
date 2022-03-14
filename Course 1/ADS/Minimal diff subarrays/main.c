#include <partition.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int size = 0;

        FILE *is = fopen(argv[1], "r");

        if (is != NULL)
        {
            fscanf(is, "%d", &size);
            int *array = calloc(size, sizeof(int));
            for (size_t i = 0; i < size; i++)
            {
                fscanf(is, "%d ", &array[i]);
            }

            int *a1, *a2, a = 0, b = 0;
            partition_array(array, size, &a1, &a, &a2, &b);

            print_array(a1, a, stdout);
            print_array(a2, b, stdout);

            printf("Difference is %d",abs(get_array_sum(a1, a) - get_array_sum(a2, b)));
            fclose(is);
        }
    }
    else
    {
        puts("No data file given!");
    }

    return 0;
}