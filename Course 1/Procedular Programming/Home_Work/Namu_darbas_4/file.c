#include <file.h>

// Get keyboard input from user
int menu_input(char *menuOptions[], int menuSize, char *inputMsg)
{
    int valid, input;
    char ch;
    do
    {
        for (int i = 0; i < menuSize; ++i)
        {
            printf("[%d]. %s\n", i + 1, menuOptions[i]);
        }
        
        printf("%s ", inputMsg);

        valid = scanf("%d", &input);

        if (valid)
        {
            ch = getchar();
        }

        valid = valid && (isspace(ch));

        if (!valid)
        {
            puts("Invalid menu input!\n");
            while(!isspace(getchar()))
                ;
        }
    } while(!valid);

    return input;
}

// Read a list of nodes from a file
void get_list(node_t** head, char *fileName)
{
    student_t std;
    FILE *fs = fopen(fileName,"r");

    if (fs != NULL)
    {
        while (!feof(fs))
        {
            if(get_student(fs, &std) == 1)
            {
                node_pushb(head, &std, sizeof(student_t));
            }        
        }

        if (fs != stdin)
        {   
            fclose(fs);
        }

        if (*head != NULL)
        {
            puts("List saved successfully!\n");
        }
        else
        {
            puts("File Error: Empty file\n");
        }
        
    }
    else
    {
        perror("File Error");
        puts("");
        return;
    }
}