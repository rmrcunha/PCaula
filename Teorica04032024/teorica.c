#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int info;
    struct Lista* prox;
} Lista;

void inserir(Lista *inicio, int valor){  
    Lista *novo = (Lista *) malloc(sizeof(int));
    novo->info=valor; // *(novo).info = valor;
    novo->prox=inicio->prox;
    inicio->prox=novo;
}