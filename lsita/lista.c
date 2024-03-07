#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Nodo *criar() {
    Nodo *inicio = (Nodo *)malloc(sizeof(Nodo));
    if (inicio == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    inicio->prox = NULL; // inicialmente a lista está vazia
    return inicio;
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

// função para inserir um elemento no início da lista
void inserir(Nodo *inicio, int valor) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->info = valor;
    novo->prox = inicio->prox;
    inicio->prox = novo;
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

void removerInicio(Nodo *inicio){
    if(inicio == NULL) exit(EXIT_FAILURE);
    Nodo *anterior = inicio;
    Nodo *atual = inicio ->prox;
    anterior->prox = atual->prox;
    free(atual);
    printf("Ultimo item excluido com sucesso.(302);\n");
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

// função para imprimir os elementos da lista
void imprimir(Nodo *inicio) {
    Nodo *atual = inicio->prox; // ignora-se o nó cabeça
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}


int achaMaior(Nodo *inicio){
    Nodo *atual = inicio, *next = inicio->prox;
    int maior =  atual ->info;
    while (next != NULL)
    {
        if (maior < atual->info && atual->info > next->info)
            maior = atual->info;
        
        atual = next;
        next = atual->prox;
    }

   return maior; 
}