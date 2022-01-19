#include <file.h>
#include <time.h>
#include <string.h>

void fillArray(int *array, int size, int low, int high);

void printArray(int *array, int size);

int main()
{
    FILE *fs = fopen("out.txt","w+b");

    //1
    int m1[5] = { 0 }, m2[5] = { 0 }, m3[5] = { 0 };
    int size = 5;

    fillArray(m1,size,10,20);
    fillArray(m2,size,10,20);
    fillArray(m3,size,10,20);

    //2
    saveToFile(m1,fs,size);

    //3
    saveToFile(m3,fs,size);

    //4
    loadFromFile(m1,&size,fs);

    //5
    FILE *fs2 = fopen("out1.txt","w+b");
    saveToFile(m2,fs2,size);

    //6
    loadFromFile(m3,&size,fs2);

    //7
    loadFromFile(m2,&size,fs);

    printf("%s", (saveCount == 3 && loadCount == 3) ? ("all good") : ("something's wrong"));

    fclose(fs);
    fclose(fs2);
    
    return 0;   
}

void printArray(int *array, int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
};


void fillArray(int *array, int size, int low, int high)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = (rand() % (high - low + 1)) + low;
    }
};