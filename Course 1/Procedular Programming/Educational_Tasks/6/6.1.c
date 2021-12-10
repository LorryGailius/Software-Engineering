#include <stdlib.h>
#include <stdio.h>

int main()
{
    long long Num, Max_Value = 20, Ats = 1;
    FILE *File;

    File = fopen("out.txt", "w");

    scanf("%lld", &Num);

    if (Num <= Max_Value && Num >= 0)
    {
        for (int i = 0; i < Num; i++)
        {
            Ats += Ats * i;
        }

        printf("%lld", Ats);
        fprintf(File, "%lld", Ats);
    }
    else
    {
        printf("Neteisinga ivestis! Iveskite Skaiciu nuo 0 iki %d\n", Max_Value);
    }

	fclose(File);

    return 0;
}