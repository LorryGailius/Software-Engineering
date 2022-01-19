#include <sort.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int size = 20;
    int arr[size];
    
    puts("");
    puts("Bubble sort:");
    fill_array(arr, size, 0, 20);
    check_sort(arr, size, bubble_sort);
    puts("");    

    puts("Quick sort:");
    fill_array(arr, size, 0, 20);
    check_sort(arr, size, quick_sort);
    puts("");

    puts("Insertion sort:");
    fill_array(arr, size, 0, 20);
    check_sort(arr, size, insertion_sort);
    puts("");

    puts("Selection sort:");
    fill_array(arr, size, 0, 20);
    check_sort(arr, size, selection_sort);
    puts("");

    puts("Merge sort:");
    fill_array(arr, size, 0, 20);
    check_sort(arr, size, merge_sort_);
    puts("");

    return 0;
}
