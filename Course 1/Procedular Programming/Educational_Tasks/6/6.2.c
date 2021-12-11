#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int Num = 0, Length = 0, Valid = 1;
    char Str, Dec[1000] = {0}, Integer [4] = {0},FileName[1000] = "in.txt";

    FILE *File;

    do
    {
        File = fopen(FileName, "r");

        fscanf(File, "%d", &Num);

        Str = fgetc(File);

        Valid = ((Num >= 10) && (Num <= 1000) && (Str == ','));

        if (!Valid)
        {
            printf("Ivestis neteisinga prasome ivesti failo varda (Pvz.: FailoPavadinimas.txt) kuriame ivestis butu teisinga:\n");
            scanf("%s",FileName);
            fclose(File);
        }
    } while (!Valid);

    int i = 0;

    while (1)
    {
        Str = fgetc(File);
        if(Str != '\n' && Str != ' ' && Str != EOF && (isdigit(Str) != 0))
        {
            Dec[i] = Str;
            i++;
        }
        else
        {
            break;
        }
    }

    Length += strlen(Dec);

    sprintf(Integer, "%d", Num);
    Length += strlen(Integer);

    printf("Faile %s esancio skaiciaus ilgis yra %d\n",FileName, Length);
    fclose(File);
    
    return 0;
}