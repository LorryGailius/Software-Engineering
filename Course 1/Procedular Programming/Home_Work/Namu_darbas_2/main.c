
// 13 Uzduotis
// Laurynas Gailius - 1 Kursas ; 2 Grupe 1 Pogrupis

// Įvesti sveiką skaičių N. Įvesti N sveikų skaičių a1, a2, ... aN. 
// Apskaičiuoti, kiek yra skaičių lygių maksimumui ir kiek lygių minimumui. 
// Išvesti įvestus skaičius, išmetus lygius maksimumui ir minimumui.

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <windows.h>

#define ARRAY_SIZE 1000

int processArgs(int argc, char **argv);
void scanInt(int *num, int maxVal, int minVal); // Scans user input from stdin
void findMaxMin(int arr[], int size, int *max, int *min, int *countMax, int *countMin); // Find Max and Min values of array and how many numbers are equal to those values
void printFilteredArray(int arr[], int size, int filter1, int filter2); // Prints out the array without the filtered numbers to stdout

int main(int argc, char **argv)
{

    if(!processArgs(argc, argv))
    {
        return 0;
    }

    int n, max, min, countMax, countMin;
    int arr[ARRAY_SIZE] = { 0 };

    scanInt(&n, ARRAY_SIZE, 0);
    printf("Enter a sequence of %d numbers\n", n);

    for (int i = 0; i < n; ++i)
    {
        scanInt(&arr[i], INT_MAX, INT_MIN);
    }
    
    findMaxMin(arr, n, &max, &min, &countMax, &countMin);

    printf
    (
        "%d number(s) are equal to maximum value of %d\n"
        "%d number(s) are equal to minimum value of %d\n",
        countMax, max, countMin, min
    );

    printf("Sequence without maximum and minimum values: \n");
    printFilteredArray(arr, n, max, min);

    return 0;
}

int processArgs(int argc, char **argv)
{
    if(argc == 1) // If there are no arguments
    {
        printf
        (
        "Enter a positive integer less than or equal to %d\n"
        "Use \"a -help\" for more information.\n",
        ARRAY_SIZE
        );
    }
    else if(argc == 2) // If there are 2 arguments
    {
        if(strcmp(argv[1], "-help") == 0) // If the argument is "--help" 
        {
            printf
            (
            "Enter a positive integer N. Enter N number of integers.\n"
            "The program will calculate how many numbers in the sequence are equal to maximum and minimum values\n"
            "It will also output the number sequence entered, discarding the maximum and minimum."
            );
        }
        else 
        {
            printf("'%s' is an invalid flag\n", argv[1]);
        }
        return 0;
    }
    else
    {
        printf("Too many arguments\n");
        return 0;
    }
}

void scanInt(int *num, int maxVal, int minVal)
{
    long long temp;
    char ch;
    int valid;

    do {
        // Check if Number is an integer and if it does not exceed memory limits
        valid = scanf("%lld", &temp) && (temp <= maxVal) && (temp > minVal);
        
        if(valid)
        {
            ch = getchar();
        }

        valid = valid && isspace(ch);

        if(!valid) 
        {
            printf("Invalid input!\n");
            do // Clear buffer
            {
                ch = getchar();
            } while (!isspace(ch));
            
        }
    } while(!valid);

    *num = temp;
}

void findMaxMin(int arr[], int size, int *max, int *min, int *countMax, int *countMin)
{
    *max = *min = arr[0];

    // Find Max and Min values
    for (int i = 0; i < size; ++i)
    {
        *max = max(arr[i], *max);
        *min = min(arr[i], *min);
    }

    *countMax = *countMin = 0;

    // Count how many numbers have a value of Min or Max
    for (int i = 0; i < size; ++i)
    {
        *countMax += (arr[i] == *max);
        *countMin += (arr[i] == *min);
    }
}

void printFilteredArray(int arr[], int size, int filter1, int filter2)
{
    // Print out the array without filtered numbers
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] != filter1 && arr[i] != filter2)
        {
            printf("%d ", arr[i]);
        }        
    }
    
    printf("\n");
}