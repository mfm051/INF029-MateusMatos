#include "EstruturaAux.h"
#include <stdlib.h>

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
        if (ultimo == NULL) // Aux vazio
            aux->head = criaElemento(valor);
        else
            ultimo->proximo = criaElemento(valor);
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

    Elemento *removido;

    if (aux->head->valor == valor)
    {
        // Atualiza head e remove antigo
        removido = aux->head;
        aux->head = aux->head->proximo;
        aux->qtd--;
        free(removido);
    }
    else
    {
        Elemento *atual = aux->head;

        while (atual && atual->proximo != NULL)
        {
            if (atual->proximo->valor == valor)
            {
                // Remove elemento
                removido = atual->proximo;
                atual->proximo = atual->proximo->proximo;
                free(removido);
                // Atualiza quantidade de elementos
                aux->qtd--;
            }

            atual = atual->proximo;
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

Elemento *removeUltimoElemento(Aux *aux)
{
    // Remoção lógica. O elemento permanece na lista, mas fica fora da "qtd"

    if (!aux->head)
    {
        // Não faz nada se aux for vazio
        return NULL;
    }

    Elemento *atual = aux->head;
    while (atual)
    {
        if (atual->proximo == NULL)
        {
            break;
        }
        atual = atual->proximo;
    }

    aux->qtd--;
    return atual;
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

void copiaElementos(Aux *aux, int *vetor, int tamanhoVetor, int posInicial)
{
    int i = posInicial;
    Elemento *atual = aux->head;

    // Impede que escrita ultrapasse o tamanho do vetor
    // e que alcance um elemento fora da estrutura auxiliar
    while (atual && (i < tamanhoVetor))
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