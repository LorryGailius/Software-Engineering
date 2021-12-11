#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validEmail(char *email);
char* getHandle(char *email);

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

        valid = valid && validEmail(buffer);

        if (!valid && strcmp(buffer,"0") != 0)
        {
            printf("Email is invalid! Enter a valid email\n");
            while(!isspace(getchar()))
                ;
        }

        if(valid && strcmp(buffer,"0") != 0)        
        {
            char *handle = getHandle(buffer);

            printf("The handle is: %s\n", handle);

            if (flag)
            {
                fprintf(file,"%s\n",buffer);
            }

            free(handle);
        }
       
    } while (strcmp(buffer,"0") != 0);

    if(file != NULL)
    {
        fclose(file);
    }

    return 0;
}


int validEmail(char *email)
{
    int etaCount = 0, etaAddress, emailLen = strlen(email), dotCount = 0;
    // Check if only one '@' symbol
    for (int i = 0; i < emailLen; ++i)
    {
        if (email[i] == '@')
        {   
            etaCount++;
            etaAddress = i;
        }
    }

    // Check if @ symbol has other characters before and after it
    if (etaCount == 1 && etaAddress < (emailLen - 1) && etaAddress > 0)
    {
        // False - if characters before and after are dots
        if (email[etaAddress - 1] == '.' || email[etaAddress + 1] == '.')
        {
            return 0;
        }
        else
        {
            for (int i = etaAddress; i <= (emailLen - 1); ++i)
            {
                // Check if dot symbol has other characters before and after it
                if (email[i] == '.')
                {
                    dotCount++;
                    // False - if there are no other characters before and after dots
                    if (email[i + 1] == '@' || email[i - 1] == '@' || i == (emailLen - 1))
                    {
                        return 0;
                    }
                }
            }
            // False - if there are no dots after '@' symbol
            if (!dotCount)
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    
    return 1;
};

char* getHandle(char *email)
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