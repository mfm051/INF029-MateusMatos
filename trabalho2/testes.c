// Testes para container

#include "container.h"
#include <stdlib.h>
#include <stdio.h>

int containerCriado()
{
    int tamanho = 1;
    Container *container = NULL;
    container = criaContainer(tamanho);

    return container && container->tamanho == 1 && container->qtd == 0;
}

int elementoInserido()
{
    Container *container = criaContainer(1);
    int novoElemento = 5;
    insereElemento(container, novoElemento);

    return container && container->qtd == 1 && container->head->valor == novoElemento;
}

int elementoNaoInserido()
{
    Container *container = criaContainer(1);
    int elemento = 5;
    insereElemento(container, elemento);
    // Capacidade do container atingida

    int novoElemento = 10;

    return container && container->qtd == 1 && container->head->valor == elemento;
}

int elementoRemovido()
{
    // Container com dois elementos de mesmo valor
    Container *container = criaContainer(2);
    int elemento = 5;
    insereElemento(container, elemento);
    insereElemento(container, elemento);

    // Elemento removido apenas uma vez
    removeElemento(container, elemento);

    return container &&
           // Quantidade de elementos alterada
           container->qtd == 1 &&
           // Head atualizado
           container->head->valor == elemento;
}

int elementoNaoRemovido()
{
    Container *container = criaContainer(1);
    int elementoNoContainer = 2;
    int elementoForaDoContainer = 3;
    insereElemento(container, elementoNoContainer);

    removeElemento(container, elementoForaDoContainer);

    return container && container->qtd == 1;
}

int tamanhoAumentado()
{
    Container *container = criaContainer(1);
    insereElemento(container, 5);

    aumentaTamanho(container, 1);
    int novoElemento = 10;
    insereElemento(container, novoElemento);

    return container->tamanho == 2 && container->head->proximo->valor == novoElemento;
}

int main()
{
    printf("Testes para container\n");

    printf("Container é criado: %d\n", containerCriado());
    printf("Elemento é inserido no container não cheio: %d\n", elementoInserido());
    printf("Elemento não é inserido no container cheio: %d\n", elementoNaoInserido());
    printf("Elemento encontrado é removido do container: %d\n", elementoRemovido());
    printf("Tentativa de remoção não altera o container: %d\n", elementoNaoRemovido());
    printf("Tamanho do conteiner é aumentado: %d\n", tamanhoAumentado());
}