#include <split.h>

int* get_sub_array_exclude(const int *const input, size_t elem_count, const int *const indices, size_t index_count) 
{
    assert(elem_count > index_count);
    int *output = (int*) malloc((elem_count - index_count) * sizeof(int));
    for(size_t i = 0, j = 0, k = 0; i < elem_count; ++i) {
        if(i == indices[j]) ++j;
        else output[k++] = input[i];
    }
    return output;
}

int* get_sub_array_include(const int *const input, size_t elem_count, const int *const indices, size_t index_count) 
{
    assert(elem_count > index_count);

    int *output = (int*) malloc(index_count * sizeof(int));
    for(size_t i = 0, j = 0; i < index_count; ++i) {
        output[j++] = input[indices[i]];
    }
    return output;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int qs_partition(int * const array, int start, int end) 
{
    int pivot_value = array[end];
    int pivot_index = start;
    for(int i = start; i < end; ++i) {
        if(array[i] > pivot_value) {
            swap(array + i, array + pivot_index);
            ++pivot_index;
        }
    }
    swap(array + pivot_index, array + end);
    return pivot_index;
}

void _quick_sort(int * const array, int start, int end) 
{
    if(start < end) {
        int index = qs_partition(array, start, end);
        _quick_sort(array, start, index - 1);
        _quick_sort(array, index + 1, end);
    }
}

void print_array(int *array, size_t n, FILE *os) {
    if(array == NULL) return;
    putc('[', os);
    for(size_t i = 0; i < n; ++i) {
        fprintf(os, "%d", array[i]);
        if(i != n - 1) {
            fprintf(os, ", ");
        }
    }
    fprintf(os, "]\n");
}

int get_array_sum(int *array, size_t n)
{
    int ret = 0;
    for (size_t i = 0; i < n; i++)
    {
        ret += array[i];
    }
    
    return ret;
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

int find_min_diff(int *array, int n)
{
    int sumOfArr = 0;
    for (size_t i = 0; i < n; i++)
    {
        sumOfArr += array[i];
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

            if (array[i - 1] <= j)
            {
                dp[i][j] |= dp[i - 1][j - array[i - 1]];
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

    return minDiff;

}

int aprox_sollution(int *array, size_t n, int **arrayL, size_t *sizeL, int **arrayR, size_t *sizeR)
{
    int sumL = 0, sumR = 0;

    int temp1[n], temp2[n];
    
    for (size_t i = 0; i < n; i++)
    {
        if (sumL < sumR)
        {
            sumL += array[i];
            temp1[(*sizeL)] = array[i];
            (*sizeL)++;
        }
        else
        {
            sumR += array[i];
            temp2[(*sizeR)] = array[i];
            (*sizeR)++;
        }
    }

    *arrayL = calloc(*sizeL, sizeof(int));
    *arrayR = calloc(*sizeR, sizeof(int));

    memcpy(*arrayL, temp1, ((*sizeL) * sizeof(int)));
    
    memcpy(*arrayR, temp2, ((*sizeR) * sizeof(int)));

    return abs(sumL - sumR);
}

int **get_variations(size_t number_of_elements_to_pick, size_t number_of_elements)
{

    assert(number_of_elements > number_of_elements_to_pick);

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
        j++;
    }
    while (prev_permuation(pick_element, pick_element + (number_of_elements)));

    return combinations;
}

void partition_array(int *array, size_t n, int **array1, size_t * n1, int **array2, size_t * n2)
{
    _quick_sort(array, 0, n - 1);
    int minDiff = find_min_diff(array, n);
    int sumpt = aprox_sollution(array,n,array1,n1,array2,n2);
    if (sumpt != minDiff)
    {
        free(array1);
        free(array2);
        // Brute force solution:
        // Generate all posible pairs of arrays and find which too have the smallest sum difference

        // Cache array sum
        const size_t S = get_array_sum(array, n);
        
        // When no exact solution exists pick one that minimises abs(sum_left - sum_right)
        int best_solution[n], best_indices[n];
        size_t min_diff = INT32_MAX, best_idx_count = 0;

        // Iterate through possible array sizes
        for(size_t i = 1; i <= n / 2; ++i) 
        {
            // Sizes of left & right subarrays
            size_t N1 = i, N2 = n - i;

            // Number of ways to distribute the elements.
            // Note: order doesn't matter since we care about the sum hence, nCr is used
            // Note: nCr(n, N1) = nCr(n, N2)
            const size_t P = nCr(n, N1); 

            // Get all combinations of indices such that sums of subarrays would be different  
            int **indices = get_variations(N1, n);  
            
            for(size_t j = 0; j < P; ++j) 
            {
                // Cache constants
                int *left_arr = get_sub_array_include(array, n, indices[j], N1); // needs to be manually freed
                const size_t left_sum = get_array_sum(left_arr, N1);
                const size_t right_sum = S - left_sum;
                const size_t sum_diff = abs(right_sum - left_sum);

                // Check if is a solution
                if(left_sum == right_sum) {
                    *n1 = N1;
                    *array1 = left_arr;
                    *n2 = N2;
                    *array2 = get_sub_array_exclude(array, n, indices[j], N1);
                    // Free indices before returning the solution
                    for(size_t j = 0; j < P; ++j) {
                        free(indices[j]);
                    }
                    free(indices);
                    return;
                }

                if(sum_diff < min_diff) {
                    min_diff = sum_diff;
                    memcpy(best_indices, indices[j], N1 * sizeof(int));
                    best_idx_count = N1;
                }
                free(left_arr);
            }
            // Free indices
            for(size_t j = 0; j < P; ++j) {
                free(indices[j]);
            }
            free(indices);
        }

    // if this point has been reached no exact solution exists
    // construct arrays with the smallest sum difference
    *n1 = best_idx_count;
    *array1 = get_sub_array_include(array, n, best_indices, best_idx_count); 
    *n2 = n - best_idx_count;
    *array2 = get_sub_array_exclude(array, n, best_indices, best_idx_count);

    }
}
