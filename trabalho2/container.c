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

void removeElemento(Container *container, int valor)
{
    if (!container->head)
        // Não faz nada se container for vazio
        return;

    if (container->head->valor == valor)
    {
        container->head = container->head->proximo;
        container->qtd--;
    }
    else
    {
        Elemento *atual = container->head;

        while (atual && atual->proximo != NULL)
        {
            if (atual->proximo->valor == valor)
            {
                // Remove elemento
                atual->proximo = atual->proximo->proximo;
                // Atualiza quantidade de elementos
                container->qtd--;
            }

            atual = atual->proximo;
        }
    }
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