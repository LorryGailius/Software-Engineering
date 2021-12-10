#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_DAY_NAME 30

int checkValidDate(int yy, int mm, int dd);

int main()
{

    int y, m, d, valid;
    char ch;

    printf("Please enter a date (YYYY-DD-MM format):\n");

    do
    {
        valid = (scanf("%d-%d-%d", &y, &m, &d) == 3);

        if (valid)
        {
            ch = getchar();
        }
        
        valid = (valid && isspace(ch));
    
        valid = (valid && checkValidDate(y, m, d));

        if (!valid)
        {
            printf("The date entered is incorrect format or does not exist!\n");
            printf("Please enter a valid date (YYYY-DD-MM format):\n");
            fflush(stdin);
        }
    } while (!valid);
    
    FILE *nameFile = NULL;

    nameFile = fopen("week.txt","r");

    valid = (nameFile != NULL);

    if (valid)
    {
        int weekday  = (d += (m < 3) ? (y--) : (y - 2), (23 * m / 9 + d + 4 + y / 4- y / 100 + y / 400)) % 7; 

        char **dayName = (char**)malloc(sizeof(char*) * 7);

        for (int i = 0; i < 7; i++)
        {
            dayName[i] = (char *)malloc(sizeof(char) * MAX_DAY_NAME);
            fscanf(nameFile,"%s",dayName[i]);
        }

        printf
        (
            "The day of the week: %s\n",
            dayName[--weekday]
        );

        for (int i = 0; i < 7; i++)
        {
            free(dayName[i]);
        }

        free(dayName);
    }
    else
    {
        printf
        (
            "week.txt does not exist or could not be opened!\n"
            "The program will now be terminated\n"
        );
    }

	fclose(nameFile);

    return 0;
}

int checkValidDate(int yy, int mm, int dd)
{
    if(yy>=1000 && yy<=9999)
    {
    //check month
        if(mm>=1 && mm<=12)
        {
        //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
            {
                return 1;
            }    
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
            {    
                return 1;
            }
            else if((dd>=1 && dd<=28) && (mm==2))
            { 
                return 1;
            }
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
            {      
                return 1;
            }
            else
            {
            return 0;
            }
        }
        else
        {
        return 0;
        }
    }
    else
    {
    return 0;
    }
};