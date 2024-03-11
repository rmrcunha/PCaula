#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
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
    printf("O maior valor da lista eh: %d\n", achaMaior(lista));
    removerInicio(lista);
    imprimir(lista);
    removerUltimo(lista);
    imprimir(lista);
    inserir(lista, 54);
    inserir(lista, 54);
    inserirUltimo(lista, 54);
    imprimir(lista);
    mataDuplicado(lista);
    imprimir(lista);
    destruir(lista);

	return 0;

}
