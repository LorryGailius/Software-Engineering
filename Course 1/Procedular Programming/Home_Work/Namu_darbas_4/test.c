// 2 Uzduotis
// Laurynas Gailius - 1 Kursas ; 2 Grupe 1 Pogrupis

// Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri įterpia prieš reikšme nurodytą 
// elementą naują elementą. Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas

#include <list.h>
#include <assert.h>

int main()
{

    node_t *head = NULL;
    int insertValue1 = 60;
    int insertValue2 = 90;
    int nodeValue1 = 4;
    int nodeValue2 = 1;

    for (int i = 1; i <= 5; ++i)
    {
        node_pushb(&head, &i, sizeof(int));
    }

    assert(*(int*)(head->data) == 1);
    
    puts("List is:");
    print_list(head, print_int, stdout);

    node_insert(&head, &nodeValue1, sizeof(int), &insertValue1, memcmp);

    assert(*(int*)(head->pNextNode->pNextNode->pNextNode->data) == insertValue1);

    node_insert(&head, &nodeValue2, sizeof(int), &insertValue2, memcmp);
    
    assert(*(int*)(head->data) == insertValue2);

    puts("List after inserts is:");
    print_list(head, print_int, stdout);
    
    clear_list(&head);

    return 0;
}