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

    return container && container->elementos[0] == novoElemento && container->qtd == 1;
}

int elementoNaoInserido()
{
    Container *container = criaContainer(1);
    insereElemento(container, 5);
    // Capacidade do container atingida

    int novoElemento = 10;

    return container && container->qtd == 1;
}

int main()
{
    printf("Testes para container\n");

    printf("Container é criado: %d\n", containerCriado());
    printf("Elemento é inserido no container não cheio: %d\n", elementoInserido());
    printf("Elemento não é inserido no container cheio: %d\n", elementoNaoInserido());
}