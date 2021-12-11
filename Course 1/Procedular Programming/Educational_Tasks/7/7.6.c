#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main()
{
    char* O[] = {"Labas", "Viso gero", "Ka"};

    printf("Selection is: %d", showMenu("Belekas", O, 3, "Pasirink tavo mama"));

    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    int valid, input;
    char ch;

    do
    {
        printf("%s\n", menuTitle);

        for (int i = 0; i < menuSize; ++i)
        {
            printf("[%d]. %s\n", i + 1, menuOptions[i]);
        }
        
        printf("%s\n", inputMsg);

        valid = scanf("%d", &input);

        if (valid)
        {
            ch = getchar();
        }
        
        valid = valid && (ch == '\n');

        valid = valid && (input > 0 && input < menuSize);

        if (!valid)
        {
            while (ch = getchar() != '\n' && ch != EOF);
        }
    } while(!valid);

    return input;
};