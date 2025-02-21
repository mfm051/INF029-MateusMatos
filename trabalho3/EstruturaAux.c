#include "EstruturaAux.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h> /* DBG */

Aux *criaAux(int tamanho)
{
    Aux *aux = (Aux *)malloc(sizeof(Aux));
    aux->tamanho = tamanho;
    aux->qtd = 0;
    aux->head = NULL;
    return aux;
}

void destroiAux(Aux *aux)
{
    if (!aux)
        return;

    Elemento *atual;

    while (aux->head)
    {
        atual = aux->head->proximo;

        free(aux->head);
        aux->head = NULL;

        aux->head = atual;
    }

    free(aux);
    aux = NULL;
}

int insereElemento(Aux *aux, int valor)
{
    if (aux->qtd < aux->tamanho)
    {
        Elemento *ultimo = encontraUltimoElemento(aux);
        Elemento *novo = criaElemento(valor);
        if (ultimo == NULL) // Aux vazio
            aux->head = novo;
        else
        {
            ultimo->proximo = novo;
            novo->anterior = ultimo;
        }
        aux->qtd++;
    }
}

void removeElemento(Aux *aux, int valor)
{
    if (!aux->head)
    {
        // Não faz nada se aux for vazio
        return;
    }

    Elemento *removido = NULL;

    if (aux->head->valor == valor)
    {
        // Atualiza head e remove antigo
        removido = aux->head;

        aux->head = aux->head->proximo;
        if (aux->head)
            aux->head->anterior = NULL;

        aux->qtd--;
        free(removido);
    }
    else
    {
        removido = encontraElemento(aux, valor);

        if (removido)
        {
            removido->anterior->proximo = removido->proximo;
            if (removido->proximo)
                removido->proximo->anterior = removido->anterior;

            aux->qtd--;
            free(removido);
        }
    }
}

Elemento *encontraElemento(Aux *aux, int valor)
{
    Elemento *atual = aux->head;
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

void removeUltimoElemento(Aux *aux)
{
    Elemento *ultimo = encontraUltimoElemento(aux);

    if (ultimo)
    {
        if (ultimo->anterior)
            ultimo->anterior->proximo = NULL;
        else
            aux->head = NULL;

        free(ultimo);
        aux->qtd--;
    }
}

void modificaTamanho(Aux *aux, int valorExtra)
{
    aux->tamanho += valorExtra;

    // Modifica quantidade se novo tamanho for menor que a quantidade de elementos
    if (aux->qtd > aux->tamanho)
    {
        int qtdParaRemover = aux->qtd - aux->tamanho;

        for (int i = 1; i <= qtdParaRemover; i++)
        {
            removeUltimoElemento(aux);
        }
    }
}

void copiaElementos(Aux *aux, int *vetor, int posInicial)
{
    int i = posInicial;
    Elemento *atual = aux->head;

    while (atual)
    {
        vetor[i] = atual->valor;
        i++;
        atual = atual->proximo;
    }
}

Elemento *encontraUltimoElemento(Aux *aux)
{
    if (aux->head == NULL)
        return aux->head;
    else
    {
        Elemento *atual = aux->head;

        while (atual->proximo != NULL)
            atual = atual->proximo;

        return atual;
    }
}

Elemento *criaElemento(int valor)
{
    Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->proximo = elemento->anterior = NULL;
    return elemento;
}