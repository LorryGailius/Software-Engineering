// 2 Uzduotis
// Laurynas Gailius - 1 Kursas ; 2 Grupe 1 Pogrupis

// Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri įterpia prieš reikšme nurodytą 
// elementą naują elementą. Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas

#include <list.h>
#include <students.h>
#include <file.h>

int main()
{
    node_t* head = NULL;
    student_t std;
    int choice, menuSize = 5;
    char *menuOptions[] = {"Read a student list from file", "Insert a student", "Print list to screen", "Print list to file", "Exit program"};
    char fileName[255];

    do
    {
        choice = menu_input(menuOptions, menuSize, "Please choose an option:");

        switch (choice)
        {
        case 1:
            printf("Enter a file to read from: ");
            scanf("%s", fileName);
            get_list(&head,fileName);
            break;

        case 2:
            if (head != NULL)
            {
                puts("Enter data of the student (name course grade): ");
                if(get_student(stdin, &std))
                {
                    if(node_insert(&head, &std, sizeof(std), &std, cmp_course))
                    {
                        puts("Student inserted successfully!\n");
                    }
                    else
                    {
                        puts("No students with such course number have been detected!");
                        puts("Student not added to the list!\n");
                    }
                }
            }
            else
            {
                puts("There is no list created or found\n");
            }
            
            break;

        case 3:
            print_list(head, print_student, stdout);
            break;

        case 4:
            printf("Enter a file to write to: ");
            scanf("%s", fileName);
            FILE *fs = fopen(fileName,"w");
            if(fs)
            {
                print_list(head, print_student, fs);                   
            }
            else
            {
                perror("File Error");
                puts("");
            }
            
            break;

        case 5:
            clear_list(&head);
            break;

        default:
            puts("Please choose an option on the menu!\n");
            break;
        }
    } while (choice != 5);

    return 0;
}