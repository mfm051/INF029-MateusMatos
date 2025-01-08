#ifndef CONTAINER_H
#define CONTAINER_H

// Estrutura "auxiliar" que abriga uma quantidade de inteiros
// determinada pelo usuário. Representada por uma lista ligada
// de elementos

typedef struct Elemento
{
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Container
{
    Elemento *head;
    int tamanho;
    int qtd; // Total de elementos adicionados
} Container;

Container *criaContainer(int tamanho);
int insereElemento(Container *container, int valor);
void removeElemento(Container *container, int valor);
Elemento *encontraElemento(Container *container, int valor);
Elemento *removeUltimoElemento(Container *container);
void aumentaTamanho(Container *container, int qtdNovosElementos);
void copiaElementos(Container *container, int *vetor);
Elemento *encontraUltimoElemento(Container *container);
Elemento *criaElemento(int valor);
// Funções auxiliares
void ordenaVetor(int *vetor, int tamanho);

#endif // CONTAINER_H