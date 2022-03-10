#include <array.h>

/// Create a sub array given the indices of elements to exclude
/// throws out the elements if their index is contained in 'indices'
/// Time complexity: O(n)
/// @param input the input array
/// @param elem_count number of elements in 'input' array
/// @param indices array of indices of elements to exclude
/// @param index_count number of elements in 'indices' array
/// @return pointer to resulting array 
int* get_sub_array_exclude(
    const int *const input, 
    size_t elem_count, 
    const int *const indices, 
    size_t index_count
) {
    assert(elem_count > index_count);
    int *output = (int*) malloc((elem_count - index_count) * sizeof(int));
    for(size_t i = 0, j = 0, k = 0; i < elem_count; ++i) {
        if(i == indices[j]) ++j;
        else output[k++] = input[i];
    }
    return output;
}

/// Create a sub array given the indices of elements to include
/// Time complexity: O(n)
/// @param input the input array
/// @param elem_count number of elements in 'input' array
/// @param indices array of indices of elements to include
/// @param index_count number of elements in 'indices' array
/// @return pointer to resulting array 
int* get_sub_array_include(
    const int *const input,
    size_t elem_count,
    const int *const indices,
    size_t index_count
) {
    assert(elem_count > index_count);

    int *output = (int*) malloc(index_count * sizeof(int));
    for(size_t i = 0, j = 0; i < index_count; ++i) {
        output[j++] = input[indices[i]];
    }
    return output;
}

/// Calculates the sum of the array
/// Time complexity: O(n)
/// @param first pointer to the first element in an array
/// @param end pointer to the end element in an array
/// @return resulting sum
size_t get_array_sum(
    const int *const first, 
    const int *const end
) {
    assert(first <= end);
    size_t sum = 0;
    for(int *it = (int*)first; it != end; ++it) {
        sum += *it;
    }
    return sum;
}


int read_int_array(
    const char * file_name, 
    int **array,
    size_t * const n
) {
    FILE *is = fopen(file_name, "rb");

    if(is == NULL) {
        fprintf(stderr, "Could not open file '%s'\n", file_name);
        return 1;
    }

    fscanf(is, "%lld", n);

    if(feof(is)) {
        fprintf(stderr, "File '%s' is empty\n", file_name);
        return 1;
    }

    *array = (int*) malloc(*n * sizeof(int));

    if(array == NULL) {
        fprintf(stderr, "Could not allocate space for input array\n");
        fclose(is);
        return 1;
    }

    for(size_t i = 0; i < *n; ++i) {
        fscanf(is, "%d", *array + i);
        if((i != *n - 1) && feof(is)) {
            fprintf(stderr, "Not enough integers in '%s'\n", file_name);
            free(*array);
            return 1;
        }
    }
    fclose(is);
    return 0;
}

void print_int_array(FILE *os, int *array, size_t n) {
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

/// Swap valyes of two integers
/// Time complexity: O(1)
/// @param a first integer
/// @param b second integer
/// @return nothing
void swap(int *const a, int *const b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/// Calculates factorial of n
/// Time complexity: O(n)
/// @param n any integer
/// @return result value
size_t fact(size_t n) {
    if(n < 2) return 1;
    return n * fact(n - 1);
}

/// Calculates n choose r
/// Time complexity: O(n)
/// @param n number of elements
/// @param r number of elements to pick
/// @return number of permutations
size_t nCr(size_t n, size_t r) {
    return fact(n) / (fact(n - r) * fact(r));
}

/// Reverses array of integers
/// Time complexity: O(n)
/// @param first pointer to the first element
/// @param end pointer to the element after the end element (weird)
/// @return nothing
void reverse_int_array(int *first, int *end) {  
    if(first == end)
        return;
    for(--end; first < end; (void)++first, --end) {
        swap(first, end);
    }
}

/// Generates lexicographically smaller permutation of an array of integers
/// Time complexity: O(n) 
/// source: https://stackoverflow.com/questions/46485506/next-permutation-time-complexity-in-big-o-notation
/// @param first pointer to the first element
/// @param end pointer to the element after the end element (weird)
/// @return 0 if no such permutation exists, 1 otherwise
uint8_t prev_permutation(int *first, int *end) {
    if (first == end) return 0;
    int *i = end;
    if (first == --i) return 0;
 
    while (1) {
        int *i1, *i2;
        i1 = i;
        if (*i1 < *--i) {
            i2 = end;
            while (!(*--i2 < *i))
                ;
            swap(i, i2);
            reverse_int_array(i1, end);
            return 1;
        }
        if (i == first) {
            reverse_int_array(first, end); //
            return 0;
        }
    }
}

/// Generates an array of all possible subarrays of size 'r' of indices 
/// Time complexity: 
/// best: O(n^2 * n!)
/// worst: O(n^2 * n!)
/// @param n total number of elements
/// @param r number of elements to pick 
/// @return array of all possible subarrays
int** get_index_permutations(const size_t n, const size_t r) {
    assert(n > r);

    // Create a mask of elements to pick
    int pick_element_n[n];
    memset(pick_element_n, 0, n * sizeof(int));
    for(size_t i = 0; i < r; ++i) {
        pick_element_n[i] = 1;
    }

    // Number of permutations
    const size_t P = nCr(n, r); 
    size_t j = 0;

    // Allocate space for the permutations
    int **perms = (int**) malloc(P * sizeof(int*));
    for(size_t i = 0; i < P; ++i) {
        perms[i] = (int*) calloc(r, sizeof(int));
    }

    // Generate permutations
    do {
        for(size_t i = 0, k = 0; i < n; ++i) {
            if(pick_element_n[i]) {
                perms[j][k++] = i;
            }
        }
        j++;
    } while(prev_permutation(pick_element_n, pick_element_n + n));
    return perms;
}


void partition_int_array(
    const int * const array, 
    size_t n, 
    int **array1, 
    size_t *n1, 
    int **array2, 
    size_t *n2
) {
    // Brute force solution:
    // Generate all posible pairs of arrays and find which too have the smallest sum difference

    // Cache array sum
    const size_t S = get_array_sum(array, array + n - 1);
    
    // When no exact solution exists pick one that minimises abs(sum_left - sum_right)
    int best_solution[n], best_indices[n];
    size_t min_diff = LLONG_MAX, best_idx_count = 0;

    // Iterate through possible array sizes
    for(size_t i = 1; i <= n / 2; ++i) {
        // Sizes of left & right subarrays
        size_t N1 = i, N2 = n - i;

        // Number of ways to distribute the elements.
        // Note: order doesn't matter since we care about the sum hence, nCr is used
        // Note: nCr(n, N1) = nCr(n, N2)
        const size_t P = nCr(n, N1); 

        // Get all combinations of indices such that sums of subarrays would be different  
        int **indices = get_index_permutations(n, N1);   
        
        for(size_t j = 0; j < P; ++j) {
            // Cache constants
            int *left_arr = get_sub_array_include(array, n, indices[j], N1); // needs to be manually freed
            const size_t left_sum = get_array_sum(left_arr, left_arr + N1 - 1);
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