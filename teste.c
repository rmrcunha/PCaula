#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int info;
    struct Nodo *next;
} Nodo;

Nodo *create();
void insert(Nodo *begin, int value);
void showAll(Nodo *current);
void deleteAll(Nodo *begin);

int main(){
    char choose;
    int v, count = 0;
    Nodo *list = create();

    while (1)
    {
        printf("Insert a new value to the list:\n");
        scanf("%d", &v);

        insert(list, v);

        while (getchar() != '\n');
        
        printf("Do you want to insert a new value?\n");
        scanf("%c", &choose);
        
        if(choose == 'n' || choose == 'N'){
            break;
        }
    }
    printf("This is your list:\n");
    showAll(list);
    deleteAll(list);
    return 0;
}

Nodo *create(){
    Nodo *begin;
    if((begin = (Nodo *)malloc(sizeof(Nodo))) == NULL){
        printf("Internal error");
        exit(EXIT_FAILURE);
    }
    begin->next = NULL;
    return begin;
}


void insert(Nodo *begin, int value){
    Nodo *new;
    if((new = (Nodo *)malloc(sizeof(Nodo))) == NULL ){
        printf("Internal Error");
        exit(1);
    };
    new->info = value;
    new->next = begin->next;
    begin->next = new;
}

void showAll(Nodo *begin){
    int i = 1;
    Nodo *current = begin->next;
    while (current != NULL)
    {
        printf("Value %d: %d\n", i, current->info);
        current = current->next;
        i++;
    }
    
}

void deleteAll(Nodo *begin){
    Nodo *current = begin->next;
    while (current != NULL)
    {
        Nodo *temp = current;
        current = current->next;
        free(temp);
    }
    free(begin);
    printf("List deleted with success!");
}