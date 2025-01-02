#include "container.h"
#include <stdlib.h>

Container *criaContainer(int tamanho)
{
    Container *container = (Container *)malloc(sizeof(Container));
    container->tamanho = tamanho;
    container->qtd = 0;
    container->head = NULL;
    return container;
}

Elemento *encontraUltimoElemento(Container *container)
{
    if (container->head == NULL)
        return container->head;
    else
    {
        Elemento *atual = container->head;

        while (atual->proximo != NULL)
            atual = atual->proximo;

        return atual;
    }
}

Elemento *criaElemento(int valor)
{
    Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->proximo = NULL;
    return elemento;
}

void insereElemento(Container *container, int valor)
{
    if (container->qtd < container->tamanho)
    {
        Elemento *ultimo = encontraUltimoElemento(container);
        if (ultimo == NULL) // Container vazio
            container->head = criaElemento(valor);
        else
            ultimo->proximo = criaElemento(valor);
        container->qtd++;
    }
}