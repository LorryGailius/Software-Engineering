#include <sort.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int size = 20;
    int arr[size];
    int testSize = 16;
    
    puts("");
    puts("Bubble sort:");
    check_sort(testSize, bubble_sort);
    puts("");    

    puts("Quick sort:");
    check_sort(testSize, quick_sort);
    puts("");

    puts("Insertion sort:");
    check_sort(testSize, insertion_sort);
    puts("");

    puts("Selection sort:");
    check_sort(testSize, selection_sort);
    puts("");

    puts("Merge sort:");
    check_sort(testSize, merge_sort_);
    puts("");

    return 0;
}
