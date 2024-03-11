#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Nodo *criar() {
    Nodo *inicio = (Nodo *)malloc(sizeof(Nodo));
    if (inicio == NULL) ERRO(1);
    inicio->prox = NULL; // inicialmente a lista está vazia
    return inicio;
}

// função para inserir um elemento no início da lista
void inserir(Nodo *inicio, int valor) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL) ERRO(2);
    novo->info = valor;
    novo->prox = inicio->prox;
    inicio->prox = novo;
}

//Insere no fim da lista
void inserirUltimo(Nodo *inicio, int valor){
    if(inicio->prox == NULL) ERRO(3);
    Nodo *atual = inicio, *next = inicio->prox, *novo;
    if((novo = (Nodo *)malloc(sizeof(Nodo))) == NULL) ERRO(3);
    while (next->prox!=NULL)
    {
        atual = next;
        next = atual->prox;
    }
    novo->info = valor;
    novo->prox = NULL;
    next->prox = novo;
}

// função para imprimir os elementos da lista
void imprimir(Nodo *inicio) {
    Nodo *atual = inicio->prox; // ignora-se o nó cabeça
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

// função para buscar um elemento na lista a partir do seu valor
Nodo *buscar(Nodo *inicio, int valor) {
    Nodo *atual = inicio->prox;
    while (atual != NULL) {
        if (atual->info == valor)
            return atual;
        atual = atual->prox;

    }
    return NULL;  // elemento não encontrado
}

// função para destruir a lista liberando a memória alocada
void destruir(Nodo *inicio) {
    Nodo *atual = inicio->prox;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(inicio); // liberação do nó cabeça
}


// função para remover um elemento da lista
void remover(Nodo *inicio, int valor) {
    Nodo *anterior = inicio;
    Nodo *atual = inicio->prox;

    // procura pelo elemento a ser removido
    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // se o elemento não foi encontrado, não há nada para remover
    if (atual == NULL) {
        printf("Elemento não encontrado na lista...\n");
        return;
    }

    // se o elemento for encontrado, então ajustam-se ponteiros e remove-o
    anterior->prox = atual->prox;
    free(atual);
}

//Acha o maior elemento
int achaMaior(Nodo *inicio){
    Nodo *atual = inicio, *next = inicio->prox;
    int maior =  atual ->info;
    while (next != NULL)
    {
        if (maior < atual->info && atual->info > next->info) maior = atual->info;
        
        atual = next;
        next = atual->prox;
    }

   return maior; 
}

//Remove o primeiro elemento
void removerInicio(Nodo *inicio){
    if(inicio == NULL) ERRO(4);
    Nodo *anterior = inicio;
    Nodo *atual = inicio ->prox;
    anterior->prox = atual->prox;
    free(atual);
    printf("Ultimo item excluido com sucesso.(302);\n");
}




//Remove o ultimo elemento
void removerUltimo(Nodo *inicio){
    if(inicio->prox ==  NULL) ERRO(5);
    Nodo *atual = inicio, *next= inicio->prox;
    while (next->prox != NULL)
    {
        atual = next;
        next = atual->prox;
    }
    if (next->prox==NULL)
    {
        free(next);
        atual->prox = NULL;
    }
    printf("Ultimo item removido com segurança\n");
}

//Percorre a lista verificando por elementos duplicados;
void mataDuplicado(Nodo *inicio){
    if (inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Nodo *atual = inicio;
    while (atual != NULL) {
        int i = 0;
        Nodo *compareAtual = atual;
        while (compareAtual != NULL && compareAtual->prox != NULL) {
            Nodo *compareNext = compareAtual->prox;
            if (compareNext->info == atual->info) {
                i++;
                printf("%d valores repetidos\n", i);
                compareAtual->prox = compareNext->prox;
                free(compareNext);
            } else {
                compareAtual = compareNext;
            }
        }
        atual = atual->prox;
    }
}
    


void ERRO(int elemento){ 
    printf("Erro no elemento %d", elemento);
    exit(EXIT_FAILURE);
}