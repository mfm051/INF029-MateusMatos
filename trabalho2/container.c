#include "container.h"
#include <stdlib.h>

Container *criaContainer(int tamanho)
{
    Container *container = (Container *)malloc(sizeof(Container));
    container->tamanho = tamanho;
    container->qtd = 0;
    container->elementos = (int *)malloc(container->tamanho * sizeof(int));
    return container;
}

void insereElemento(Container *container, int elemento)
{
    if (container && (container->qtd < container->tamanho))
    {
        container->elementos[container->qtd] = elemento;
        container->qtd++;
    }
}