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

int insereElemento(Container *container, int valor)
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

Elemento *encontraElemento(Container *container, int valor)
{
    Elemento *atual = container->head;
    while (atual)
    {
        if (atual->valor == valor)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

Elemento *removeUltimoElemento(Container *container)
{
    Elemento *atual = container->head;
    while (atual)
    {
        if (atual->proximo == NULL)
        {
            break;
        }
        atual = atual->proximo;
    }
    container->qtd = container->qtd > 0 ? container->qtd - 1 : container->qtd;
    return atual;
}

void modificaTamanho(Container *container, int incremento)
{
    container->tamanho += incremento;

    // Modifica quantidade se novo tamanho for menor que a quantidade de elementos
    if (container->qtd > container->tamanho)
    {
        int qtdParaRemover = container->qtd - container->tamanho;

        for (int i = 1; i <= qtdParaRemover; i++)
        {
            removeUltimoElemento(container);
        }
    }
}

void copiaElementos(Container *container, int *vetor, int posInicial)
{
    int i = posInicial;
    Elemento *atual = container->head;
    while (atual)
    {
        vetor[i] = atual->valor;
        i++;
        atual = atual->proximo;
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

void ordenaVetor(int *vetor, int tamanho)
{
    // Ordenação por insertion sort
    int key, j, temp;
    for (int i = 1; i < tamanho; i++)
    {
        key = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > key)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;
    }
}