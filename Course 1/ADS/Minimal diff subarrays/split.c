#include <split.h>

void print_array(int *arr, size_t n, FILE *os) {
    if(arr == NULL) return;
    putc('[', os);
    for(size_t i = 0; i < n; ++i) {
        fprintf(os, "%d", arr[i]);
        if(i != n - 1) {
            fprintf(os, ", ");
        }
    }
    fprintf(os, "]\n");
}

int get_array_sum(int *arr, size_t n)
{
    int ret = 0;
    for (size_t i = 0; i < n; i++)
    {
        ret += arr[i];
    }
    
    return ret;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t factorial(size_t n)
{
    int f = 1;
    for (size_t i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

size_t nCr(size_t n, size_t r)
{
    int ret = (factorial(n)) / (factorial(r) * factorial(n - r));
    return ret;
}

void reverse(int *first, int *last)
{
    if(first == last) return;
    for (--last; first < last; first++, --last)
    {
        swap(first, last);
    }
}

int prev_permuation(int *first, int *last)
{
    if (first == last) return 0;
    int *i = last;
    if (first == --i) return 0;
 
    while (1) 
    {
        int *i1, *i2;
 
        i1 = i;
        if (*i1 < *--i) {
            i2 = last;
            while (!(*--i2 < *i))
                ;
            swap(i, i2);
            reverse(i1, last);
            return 1;
        }
        if (i == first) {
            reverse(first, last);
            return 0;
        }
    }
}

int **get_variations(size_t number_of_elements_to_pick, size_t number_of_elements)
{

    if(number_of_elements < number_of_elements_to_pick){return NULL;}

    int *pick_element = (int *)calloc(number_of_elements, sizeof(int));
    for (size_t i = 0; i < number_of_elements_to_pick; i++)
    {
        pick_element[i] = 1;
    }
    int len = nCr(number_of_elements,number_of_elements_to_pick);

    int **combinations = (int **)calloc(len, sizeof(int*));

    for (size_t i = 0; i < len; i++)
    {
        combinations[i] = (int *)calloc(number_of_elements_to_pick, sizeof(int));
    }

    size_t j = 0;
    do
    {
        size_t count = 0;
        for (size_t i = 0; i < number_of_elements; i++)
        {
            if (pick_element[i])
            {
                combinations[j][count++] = i;
            } 
        }
        
        print_array(combinations[j], number_of_elements_to_pick, stdout);
        fflush(stdout);
        j++;
    }
    while (prev_permuation(pick_element, pick_element + (number_of_elements)));

    return combinations;
}

void partition_array(int *arr, int *part1, int *part2, size_t n, size_t n1, size_t n2)
{


}

int find_min_diff(int *arr, int n)
{
    int sumOfArr = 0;
    for (size_t i = 0; i < n; i++)
    {
        sumOfArr += arr[i];
    }
    
    int sum = sumOfArr/2;

    int dp[n + 1][sum + 1];

    for (size_t i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (size_t i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (arr[i - 1] <= j)
            {
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    int minDiff = INT_MAX;

    for (size_t i = sum; i >= 0; i--)
    {
        if (dp[n][i])
        {
            minDiff = sumOfArr - (2 * i);
            break;
        }
    }
    
    printf("Minimum difference is : %d", minDiff);

    return minDiff;

}

