#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validEmail(char *email);
char* printHandle(char *email);

int main()
{
    int valid = 0, flag = 0;
    char buffer[256] = { 0 };

    printf
    (
        "Enter a list of emails\n"
        "Enter 0 to end the program\n"
    );

    FILE *file = fopen("emails.txt","a");
    flag = (file != NULL);

    if (!flag)
    {
        printf("emails.txt could not be created! no emails will be saved!\n");
    }
    
    do
    {
        valid = (scanf("%255s", buffer));

        valid = validEmail(buffer);

        if (!valid && strcmp(buffer,"0") != 0)
        {
            printf("Email is invalid! Enter a valid email\n");
            while(!isspace(getchar()))
                ;
        }

        if(valid && strcmp(buffer,"0") != 0)        
        {
            char *handle = printHandle(buffer);

            printf("The handle is: %s\n", handle);

            if (flag)
            {
                fprintf(file,"%s\n",buffer);
            }

            free(handle);
        }
       
    } while (strcmp(buffer,"0") != 0);

    fclose(file);

    return 0;
}


int validEmail(char *email)
{
    int valid = 0, etaCount = 0, addres, dotNum = 0;
    //check if only one @ symbol
    for (int i = 0; i < strlen(email); ++i)
    {
        if (email[i] == '@')
        {
            etaCount++;
            addres = email[i];
        }
    }

    if (etaCount == 1)
    {
        //check if there are symbols between '.' and '@'
        for (int i = 0; i < strlen(email); ++i)
        {
            if (email[i] == '.' && email[i] < addres)
            {
                for (int j = i; j < strlen(email); ++j)
                {
                    if (email[j] == '@')
                    {
                        if ((j-i) > 1)
                        {
                            valid = 1;
                        }
                        else
                        {
                            valid = 0;
                        }
                        break;
                    }
                }
            }
        }
        //Check if there is a '.' after @ symbol
        if(valid)
        {
            int flag = 0;
            for (int i = 0, j = 0; i < strlen(email); ++i)
            {
                if (email[i] == '@')
                {
                flag = 1;
                }

                if (flag)
                {
                    if (email[i] == '.')
                    {
                        dotNum++;
                    }
                }
            }
            if (dotNum == 0)
            {
                valid = 0;
            }
        }
    }

    return valid;
};

char* printHandle(char *email)
{
    int emailLen = strlen(email);
    char *handle = (char *)calloc(256,sizeof(char));
    int flag = 0;
    for (int i = 0, j = 0; i < emailLen; ++i)
    {
        if (email[i] == '@')
        {
            flag = 1;
        }

        if (flag)
        {
            handle[j++] = email[i];
        }
    }
    return handle;
};