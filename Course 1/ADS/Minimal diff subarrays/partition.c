#include <partition.h>

/*
    Create a sub-array given the indices of elements to exclude
    throws out the elements if their index is contained in 'indices' array
    Time complexity : O(n)
    @param input the input array
    @param elem_count number of elements in 'input' array
    @param indices array of indices of elements to exclude
    @param index_count number of elements in 'indices' array
    @return pointer to resulting array 
*/
int* get_sub_array_exclude(const int *const input, size_t elem_count, const int *const indices, size_t index_count) 
{
    assert(elem_count > index_count);
    int *output = (int*) malloc((elem_count - index_count) * sizeof(int));
    for(size_t i = 0, j = 0, k = 0; i < elem_count; ++i) 
    {
        if(i == indices[j]) ++j;
        else output[k++] = input[i];
    }
    return output;
}

/*
    Create a sub-array given the indices of elements to include
    Time complexity : O(n)
    @param input the input array
    @param elem_count number of elements in 'input' array
    @param indices array of indices of elements to include
    @param index_count number of elements in 'indices' array
    @return pointer to resulting array 
*/
int* get_sub_array_include(const int *const input, size_t elem_count, const int *const indices, size_t index_count) 
{
    assert(elem_count > index_count);

    int *output = (int*) malloc(index_count * sizeof(int));
    for(size_t i = 0, j = 0; i < index_count; ++i) 
    {
        output[j++] = input[indices[i]];
    }
    return output;
}

/*
    Swap two values
    Time complexity: O(1)
    @param a first value
    @param b second value
    @return -
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    Given an array, start and end indices, put x at its correct position in sorted array
    Time complexity: O(n)
    @param array pointer to array to partition from  
    @param start index value of starting position in array
    @param end index value of end position in array
    @return pivot index value
*/
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

/*
    Given an array, start and end indices, sort the array by using 'quick sort' algorithm
    Function uses recursion
    Time complexity : 
    Best : O(n*log(n))
    Worst : O(n^2)
    @param array pointer to array to partition from  
    @param start index value of starting position in array
    @param end index value of end position in array
    @return -
*/
void _quick_sort(int * const array, int start, int end) 
{
    if(start < end) {
        int index = qs_partition(array, start, end);
        _quick_sort(array, start, index - 1);
        _quick_sort(array, index + 1, end);
    }
}

/*
    Given an array and size 'n' prints out it's values to given file stream
    @param array array to print elements of
    @param n number of elements to print
    @param os file stream to print out to. 'stdout' - print to screen.
    @return -
*/
void print_array(const int *array, size_t n, FILE *os) 
{
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
/*
    Calculates the sum of the array
    Time complexity: O(n)
    @param first pointer to the first element in an array
    @param end pointer to the end element in an array
    @return resulting sum
*/
int get_array_sum(const int *array, size_t n)
{
    int ret = 0;
    for (size_t i = 0; i < n; i++)
    {
        ret += array[i];
    }
    
    return ret;
}

/*
    Calculates the factorial of n
    Time complexity: O(n)
    @param n integer value
    @return factorial value
*/
size_t factorial(size_t n)
{
    size_t f = 1;
    for (size_t i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

/*
    Calculates n choose r
    Time complexity: O(n)s
    @param n number of elements
    @param r number of elements to pick
    @result number of possible variations
*/
uint64_t nCr(int n, int r)
{
    int sum=1,t=1;
    while(N!=t)
    {
    sum=sum*(N/t);
    N--; t++;
    }
    return sum;
}

/*
    Reverses array
    Time complexity: O(n)
    @param start pointer to the start of array
    @param end pointer to the end of array
    @return -
*/
void reverse(int *start, int *end)
{
    if(start == end) return;
    for (--end; start < end; start++, --end)
    {
        swap(start, end);
    }
}

/*
    Generate smaller permutation of array
    Time complexity: O(n)
    @param start pointer to first element in array
    @param end pointer to the element after the end of array
    @return 1 - if permutation exists 0 - if its does not 
*/
int prev_permuation(int *start, int *end)
{
    if (start == end) return 0;
    int *i = end;
    if (start == --i) return 0;
 
    while (1) 
    {
        int *i1, *i2;
 
        i1 = i;
        if (*i1 < *--i) {
            i2 = end;
            while (!(*--i2 < *i))
                ;
            swap(i, i2);
            reverse(i1, end);
            return 1;
        }
        if (i == start) {
            reverse(start, end);
            return 0;
        }
    }
}

/*
    Find minimum sum difference of two sub-arrays, when partitioning an array into two subsets
    Time complexity: O(n * sum)
    @param array array to partition into two subsets
    @param n number of elements in array
    @return minimum difference possible
*/
int find_min_diff(const int *array, int n)
{
    int sumOfArr = get_array_sum(array, n);
    
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

/*
    'Greedy' approach to partition an array into two subsets, that their sum difference is as small as possible
    Used in 'partition_array' in order to minimize time complexity if possible
    Changes the values
    Time complexity: O(n)
    @param array array to partition into two subsets
    @param n number of elements in 'array'
    @param array1 pointer to first subset array
    @param n1 pointer to number of elements in 'array1'
    @param array2 pointer to second subset array
    @param n2 pointer to number of elements in 'array2'
    @return minimum difference found by the 'greedy' approach. 'array1' & 'array2' must be empty in order to be filled!
*/
int aprox_sollution(const int *array, size_t n, int **array1, size_t *n1, int **array2, size_t *n2)
{
    int sumL = 0, sumR = 0;
    *n1 = 0;
    *n2 = 0;
    int temp1[n], temp2[n];
    
    for (size_t i = 0; i < n; i++)
    {
        if (sumL < sumR)
        {
            sumL += array[i];
            temp1[(*n1)] = array[i];
            (*n1)++;
        }
        else
        {
            sumR += array[i];
            temp2[(*n2)] = array[i];
            (*n2)++;
        }
    }

    free(*array1);
    free(*array2);
    *array1 = calloc(*n1, sizeof(int));
    *array2 = calloc(*n2, sizeof(int));

    if (*array1 == NULL && *array2 == NULL) { return INT_MAX; }

    memcpy(*array1, temp1, ((*n1) * sizeof(int)));

    memcpy(*array2, temp2, ((*n2) * sizeof(int)));

    return abs(sumL - sumR);
}

/*
    Generates an array of all possible subarrays of size 'r' indices 
    Time complexity: O(n^2 * n!)
    @param n total number of elements
    @param r number of elements to pick 
    @return array of all possible subarrays
*/
int **get_variations(size_t n, size_t r)
{

    assert(r > n);

    int *pick_element = (int *)calloc(r, sizeof(int));
    
    for (size_t i = 0; i < n; i++)
    {
        pick_element[i] = 1;
    }
    int len = nCr(r,n);

    int **combinations = (int **)calloc(len, sizeof(int*));

    for (size_t i = 0; i < len; i++)
    {
        combinations[i] = (int *)calloc(n, sizeof(int));
    }

    size_t j = 0;
    do
    {
        size_t count = 0;
        for (size_t i = 0; i < r; i++)
        {
           
            if (pick_element[i])
            {
                combinations[j][count++] = i;
            } 
        }
        j++;
    }
    while (prev_permuation(pick_element, pick_element + (r)));

    return combinations;
}

/*
    Partitions a set into two subsets such that the difference of subset sums is minimum
    Uses 'greedy' aproximate approach, else brute force
    Time complexity: 
    best : O(n * sum)
    worst : O(n ^ 2 * n!)
    @param array array to partition into two subsets
    @param n number of elements in 'array'
    @param array1 pointer to first subset array
    @param n1 pointer to number of elements in 'array1'
    @param array2 pointer to second subset array
    @param n2 pointer to number of elements in 'array2'
    @return given pointers point to created arrays which are subsets of 'array'
*/
void partition_array(int *array, size_t n, int **array1, size_t * n1, int **array2, size_t * n2)
{
    _quick_sort(array, 0, n - 1); // Sort the array in reverse order
    int minDiff = find_min_diff(array, n); // Find minimum subset difference possible
    int sumpt = aprox_sollution(array,n,array1,n1,array2,n2); // 'greedy' approach subset difference found
    printf("Minimum difference is: %d | Greedy approach found: %d\n", minDiff, sumpt);
    if (sumpt != minDiff)
    {
        // Initiate brute force solution:
        free(array1);
        free(array2);
        
        // Generate all posible pairs of arrays and find which two have the smallest sum difference
        const size_t S = get_array_sum(array, n);
        
        // When no exact solution exists pick one that minimises subset difference
        int best_indices[n];
        size_t min_diff = INT32_MAX, best_idx_count = 0;

        // Iterate through possible array sizes
        for(size_t i = n / 4; i <= n / 2; ++i) 
        {
            // Sizes of left & right subarrays
            size_t N1 = i, N2 = n - i;

            // Number of ways to distribute the elements.
            printf("N : %d | R : %d\n", n, N1);
            const uint64_t P = nCr(n, N1); 
            printf("%d", P);
            // Get all combinations of indices such that sums of subarrays would be different  
            int **indices = get_variations(N1, n);  
            for(size_t j = 0; j < P; ++j) 
            {
                int *left_arr = get_sub_array_include(array, n, indices[j], N1); // needs to be manually freed
                const size_t left_sum = get_array_sum(left_arr, N1);
                const size_t right_sum = S - left_sum;
                const size_t sum_diff = abs(right_sum - left_sum);

                // If array can be divided exactly in half
                if(left_sum == right_sum) 
                {
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

                if(sum_diff < min_diff) 
                {
                    min_diff = sum_diff;
                    memcpy(best_indices, indices[j], N1 * sizeof(int));
                    best_idx_count = N1;
                }
                free(left_arr);
            }
            // Free indices
            for(size_t j = 0; j < P; ++j) 
            {
                free(indices[j]);
            }
            free(indices);
        }

    // Construct arrays with the smallest sum difference
    *n1 = best_idx_count;
    *array1 = get_sub_array_include(array, n, best_indices, best_idx_count); 
    *n2 = n - best_idx_count;
    *array2 = get_sub_array_exclude(array, n, best_indices, best_idx_count);
    }
}