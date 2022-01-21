#include <sort.h>

void fill_array(long *array, long size, long low, long high)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % (high - low + 1)) + low;;
    }
}

void print_array(long *array, long size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}

void check_sort(long maxSize, sort_func_t func)
{   
    int size = 100000, flag = 1, j = 1;
    float time = 0;
    for(int j = 1; j <= maxSize; j++)
    {
        int array[size];
        fill_array(array, size, -size, size);
        clock_t tic = clock();
        func(array, size);
        clock_t toc = clock();
        time += ((float)(toc - tic) / CLOCKS_PER_SEC);

        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                printf("%d !< %d", array[i], array[i + 1]);
                flag = -1;
                printf("Array %d was sorted incorrectly!\n", j);
                if (size < 1000)
                {
                    print_array(array, size);
                }
                break;
            }
        }
    }
    if (flag == 1)
    {
        printf("%d arrays with %d random elements were sorted correctly!\n", maxSize, size);
    }

    printf("Average time for sorting algorithm was %lf", (time/(float)(maxSize)));

}

void swap(int * a, int * b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            temp = array[i];
            array[i + 1] = temp;
            array[i] = array[i + 1];
        }
    }
}

void quick_sort (int * const array, int num) 
{
    _quick_sort(array, 0, num - 1);
}

void _quick_sort(int * const array, int start, int end) 
{
    if(start < end) {
        int index = qs_partition(array, start, end);
        _quick_sort(array, start, index - 1);
        _quick_sort(array, index + 1, end);
    }
}

int qs_partition(int * const array, int start, int end) 
{
    int pivot_value = array[end];
    int pivot_index = start;
    for(int i = start; i < end; ++i) {
        if(array[i] < pivot_value) {
            swap(array + i, array + pivot_index);
            ++pivot_index;
        }
    }
    swap(array + pivot_index, array + end);
    return pivot_index;
}

void insertion_sort(int *array, int size)
{
    int num, p;
    for (int i = 1; i < size; i++)
    {
        num = array[i];
        p = i -1;

        while (array[p] > num && p >= 0)
        {
            array[p + 1] = array[p];
            p--;
        }
        
        array[p + 1] = num;
    }
}

void selection_sort(int *array, int size)
{
    int index, temp;

    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[index] > array[j])
            {
                index = j;
            }
        }
            temp = array[index];
            array[index] = array[i];
            array[i] = temp;
    }
}

void merge_sort(int *array, int l, int r)
{
    if (l > r)
    {
        return;
    }
    
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void merge(int *array, int l, int m, int r)
{
    int s1 = m - l + 1;
    int s2 = r - m;
  
    int leftArray[s1], rightArray[s2];
  
    for (int i = 0; i < s1; i++)
        leftArray[i] = array[l + i];
    for (int j = 0; j < s2; j++)
        rightArray[j] = array[m + 1 + j];

    int i = 0;
    int k = l;
    int j = 0;

    while (i < s1 && j < s2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }
    }

    while (i < s1)
    {
        array[k] = leftArray[i];
        k++;
        i++;
    }
    
    while (j < s2)
    {
        array[k] = rightArray[j];
        k++;
        j++;
    }
}

void merge_sort_(int *array, int size)
{
    merge_sort(array, 0, size);
}