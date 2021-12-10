#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int min(int a, int b);
int max(int a, int b);

int main()
{

    int NumValid, FileValid, Num1 = 0, Num2 = 0, Num3 = 0;
    char Ch, FileName[1000] = {0};

    srand(time(NULL));

    printf
    (
        "Iveskite tris skaicius atskirtus kabliataskiais\n"
        "Pvz.: %d;%d;%d\n",
        (rand() / 50), (rand() / 40), (rand() / 30)    
    );

    do
    {
        NumValid = (scanf("%d;%d;%d",&Num1,&Num2,&Num3) == 3);

        if (NumValid)
        {
            Ch = getchar();
        }

        NumValid = NumValid && (Ch == ' ' || Ch == '\n');

        if(!NumValid)
        {
            printf
            (
                "Ivestis neteisinga. Iveskite tris skaicius atskirtus kabliataskiais\n"
                "Pvz.: %d;%d;%d\n",
                rand() / 50,rand() / 40, rand() / 30
            );

            fflush(stdin);
        }

    } while(!NumValid);

    int Min = min(min(Num1,Num2),Num3);
    int Max = max(max(Num1,Num2),Num3);
    int Mid = Num1 + Num2 + Num3 - Min - Max;

    printf
    (
        "Iveskite faila i kuri norite saugoti\n"
        "Pvz.: FailoPavadinimas.txt\n"    
    );

    do
    {
        scanf("%s",FileName);

        FileValid = (strlen(FileName) > 4) && !(strcmp(&FileName[strlen(FileName) - 4], ".txt"));

        if (!FileValid)
        {
            printf
            (
                "Ivestis neteisinga. Iveskite faila i kuri norite saugoti\n"
                "Pvz.: FailoPavadinimas.txt\n"    
            ); 

            fflush(stdin);
        }
        
    } while (!FileValid);

    FILE *File;

    File = fopen(FileName,"w");

    fprintf
    (
        File,
        "Ivesti skaiciai yra : %d;%d;%d\n"
        "Vidurinis (pagal reiksme) skaicius yra : %d\n"
        ,Num1, Num2, Num3, Mid
    );

    return 0;
}

int min(int a, int b)
{
    int Ans;
    Ans = (a < b) ? a : b;
    return Ans;
};

int max(int a, int b)
{
    int Ans;
    Ans = (a > b) ? a : b;
    return Ans;
};