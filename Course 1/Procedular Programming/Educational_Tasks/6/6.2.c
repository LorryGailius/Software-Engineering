#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int Num = 0, Num2 = 0, Length = 0, Valid = 1;
    char Ch, Dec[1000] = { 0 }, FileName[256] = "in.txt";

    FILE *File;

    do
    {
        File = fopen(FileName, "r");

        fscanf(File, "%d", &Num);

        Ch = fgetc(File);

        Valid = ((Num >= 10) && (Num <= 1000) && (Ch == ',') && (File));
		
		Valid = Valid && fscanf(File, "%d", &Num2);
		
		Ch = fgetc(File);
		
		Valid = Valid && (Ch == EOF);

        if (!Valid)
        {
            printf("Ivestis neteisinga prasome ivesti failo varda (Pvz.: FailoPavadinimas.txt) kuriame ivestis butu teisinga:\n");
            scanf("%s",FileName);
            fclose(File);
        }
    } while (!Valid);

    sprintf(Dec,"%d",Num);
	Length += strlen(Dec);
	sprintf(Dec,"%d",Num2);
	Length += strlen(Dec);

    printf("Faile %s esancio skaiciaus ilgis yra %d\n",FileName, Length);
    fclose(File);
    
    return 0;
}