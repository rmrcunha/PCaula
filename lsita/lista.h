// definição da estrutura da lista encadeada simples
typedef struct Nodo {
    int info;
    struct Nodo *prox;
} Nodo;

// protótipos das funções
Nodo *criar();
void imprimir(Nodo *inicio);
int achaMaior(Nodo *inicio);
void inserir(Nodo *inicio, int valor);
void inserirUltimo(Nodo *inicio, int valor);
Nodo *buscar(Nodo *inicio, int valor);
void remover(Nodo *inicio, int valor);
void removerInicio(Nodo *inicio);
void removerUltimo(Nodo *inicio);
void mataDuplicado(Nodo *inicio);
void destruir(Nodo *inicio);
void ERRO(int elemento);