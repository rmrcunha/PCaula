#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Nodo *create();
void createAtTheEnd(Nodo *current, int value);
void showAll(Nodo *begin);
void deleteAll(Nodo *begin);

int main(){
    Nodo *list = create();
    for(int i; i<=5; i++) createAtTheEnd(list, i);
    
    showAll(list);
    destruir(list);
}

Nodo *create(){
    Nodo *begin;

    if((begin=(Nodo*)malloc(sizeof(Nodo))) == NULL){
        printf("Error 1;");
        exit(EXIT_FAILURE);
    }   
    begin->prox=NULL;
    return begin;
}

void createAtTheEnd(Nodo *current, int value){
    Nodo *new;
    if((new = (Nodo *)malloc(sizeof(Nodo))) == NULL){
        printf("Error 2");
        exit(EXIT_FAILURE);
    }
    while (current->prox != NULL) current = current->prox;
    new->info = value;
    current->prox = new;
    new->prox = NULL;
}

void showAll(Nodo *begin){
    int i = 1;
    Nodo *current = begin->prox;
    while(current != NULL){
        printf("Value %d: %d\n", i, current->info);
        current = current ->prox;
        i++;
    }
}