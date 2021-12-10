#include <stdio.h>
#include <stdlib.h>

int main()
{
    int integer = 0, decimal = -1, einteger = 0, edecimal = -1, valid, flag = 1;
    char ch, fileName[256] = { 0 }, handle[10] = { 0 };

	printf
	(
		"FILE GENERATOR\n"
		"The program generates files with a specific handle (ex. \".txt\")\n"
        "Specify a start range, end range and handle to generate a list of files\n"
        "(ex. \"1.0\", \"1.5\", \".txt\" will generate \".txt\" files from 1.1 to 1.5)\n"
        "IN CASE OF ERROR THE PROGRAM TERMINATES ITSELF\n\n\n"
	);

    printf("Specify start number: ");

    valid = scanf("%d", &integer);

    if (valid)
    {
        ch = getchar();
		return 0;
    }

    valid = valid && (ch == '.' || ch == '\n');

    if (!valid)
    {
        while (getchar() != '\n')
            ;
        return 0;
    }
    
    if (valid && ch == '.')
    {
        valid = scanf("%d", &decimal);
    }

    if (!valid)
    {
        while (getchar() != '\n')
            ;
        return 0;
    }
    
    printf("Specify end number: ");

    valid = valid && scanf("%d", &einteger);

    if (valid)
    {
        ch = getchar();
    }

    valid = valid && (ch == '.' || ch == '\n');

    if (!valid)
    {
        while (getchar() != '\n')
            ;
        return 0;
    }

    if (valid && ch == '.')
    {
        valid = scanf("%d", &edecimal);
    }

    if (!valid)
    {
        while (getchar() != '\n')
            ;
        return 0;
    }

    printf("Specify handle: ");

    scanf("%s",handle);

    if (decimal == -1 && edecimal == -1)
    {
        printf
        (
            "Start file : %d%s\n"
            "End file : %d%s\n",
            integer, handle, einteger, handle
        );

        for (int i = integer; i <= einteger; i++)
        {
            sprintf(fileName,"%d%s", i, handle);
            FILE *file = fopen(fileName,"w");
            if (file == NULL)
            {
                flag = 0;
            }
            fclose(file);
        }
    }
    else if (decimal > -1 && edecimal > -1)
    {    
        for (int i = integer; i <= einteger; i++)
        {
            for (int j = 1; j <= edecimal; j++)
            {
                sprintf(fileName,"%d.%d%s", i, j, handle);
                FILE *file = fopen(fileName,"w");
                if (file == NULL)
                {
                    flag = 0;
                }
                fclose(file);
            }   
        }
    }
    
    if (flag == 0)
    {
        printf("There was an error creating files\n");
    }
    
    return 0;
}