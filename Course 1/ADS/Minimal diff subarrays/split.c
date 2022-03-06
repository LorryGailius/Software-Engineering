#include <split.h>
#include <sort.h>

void split(int *arr, int size, FILE *os, int printArray)
{
    int sum = 0;

    int prefix = 0;
    int minDiff = INT_MAX;
    int index;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    
    for (int i = 0; i < size - 1; i++)
    {
        prefix += arr[i];
        int diff = abs(prefix - (sum - prefix));

        if (diff < minDiff)
        {
            minDiff = diff;
            index = i;
        }
    }

    if(printArray > 0)
    {
        for (int i = 0; i <= index; i++)
        {
            fprintf(os, "%d ", arr[i]);
        }
        puts("");
        for (int i = index + 1; i < size; i++)
        {
            fprintf(os, "%d ", arr[i]);
        }
    }
    else
    {
        fprintf(os, "Minimum difference is: %d\n", minDiff);
    }

    if (os != stdout)
    {
        fclose(os);
    }
}

void finMinDiff(int *arr, int size)
{

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    
    int dp[size + 1][sum + 1];

    for (int i = 0; i <= size; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
           
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    printf("  1 2 3 4 5 6\n");

    for (int i = 1; i < size - 1; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= sum; j++)
        {
            printf("%d ", dp[i][j]);
        }
        puts("");
    }
    

    
    int diff = INT_MAX;

    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[size][i])
        {
            diff = sum - 2 * i;
            break;
        }
    }
    
    printf("%d", diff);
}