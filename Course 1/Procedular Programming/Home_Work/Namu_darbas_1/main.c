
//9 Uzduotis
//Laurynas Gailius - 1 Kursas ; 2 Grupe 1 Pogrupis

/*
Prašoma įvesti sveiką skaičių A. Įvedinėti sveikų skaičių seką tol, kol vienas po kito įvestų 
skaičių skirtumo modulis bus mažesnis už A. Išvesti didžiausią ir mažiausią sekos narius.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>

void ScanInt(int *x,int MaxValue);

int main()
{
    int Num1, Num2, Num3, Min, Max, Mod;

    printf("Iveskite sveika skaiciu: ");

    ScanInt(&Num1, 1);

    printf
    (
        "Iveskite sveiku skaiciu seka.\n"
        "Ivedus kiekviena elementa spauskite enter klavisa\n"
        "(Programa veiks tol, kol vienas po kito ivestu skaiciu skirtumo modulis bus mazesnis uz %d)\n"
        ,Num1
    );

    ScanInt(&Num2,0); //Scan first member of sequence
    Max = Min = Num3 = Num2;

    do
    {
        ScanInt(&Num2,0);

        Min = min(Num2,Min);
        Max = max(Num2,Max);

        Mod = abs(Num3 - Num2);
        Num3 = Num2;
    } while (Num1 >= Mod);

    printf("Didziausia sekos reiksme yra : %d\n", Max);
    printf("Maziausia sekos reiksme yra : %d\n", Min);
    
    return 0;
}

void ScanInt(int *x, int MaxValue)
{
    long long Num;
    int Ch, Correct;
    do
    {
        // Check if Number is an integer and if it does not exceed memory limits
        Correct = scanf("%lld%c",&Num,&Ch)  && (Ch == '\n') && (Num <= (INT_MAX - MaxValue)) && (Num >= INT_MIN);
        
        if(!Correct)
        {
            printf("Ivestis neteisinga\n");

            fflush(stdin);
        }

    } while (!Correct);

    *x = Num;
}