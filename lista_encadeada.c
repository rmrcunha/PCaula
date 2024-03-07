#include <stdio.h>
#include <stdlib.h>

// definição da estrutura da lista encadeada simples
typedef struct Nodo {
    int info;
    struct Nodo *prox;
} Nodo;

// protótipos das funções
Nodo *criar();
void destruir(Nodo *inicio);
void inserir(Nodo *inicio, int valor);
void remover(Nodo *inicio, int valor);
Nodo *buscar(Nodo *inicio, int valor);
void imprimir(Nodo *inicio);

// função main para testa das funções
int main () {

	Nodo *lista = criar();

    // inserindo elementos na lista
    inserir(lista, -1);
    inserir(lista, -10);
    inserir(lista, -100);
    for (int i = 0; i < 10; i++)
    	inserir(lista, i);

    // imprimindo a lista
    printf("Nodo após inserção dos elementos: ");
    imprimir(lista);

    // removendo um elemento da lista
    remover(lista, 5);

    // imprimindo a lista após a remoção
    printf("Nodo após remoção do elemento 5: ");
    imprimir(lista);

    // buscando um elemento na lista
    int valor = 7;
    Nodo *resultado = buscar(lista, valor);
    if (resultado != NULL)
        printf("O elemento %d está na lista.\n", valor);
    else
        printf("O elemento %d não está na lista.\n", valor);

    // destruição da lista
    destruir(lista);

	return 0;

}

// função para criar uma lista vazia com cabeçalho
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