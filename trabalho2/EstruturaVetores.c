#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int tamanho)
{
    posicao = getPosicaoNoVetor(posicao);

    // Posição deve ser um valor válido
    if (posicao == -1)
    {
        return POSICAO_INVALIDA;
    }

    // Na posicao pode já existir estrutura auxiliar
    if (vetorPrincipal[posicao] != NULL)
    {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    // O tamanho nao pode ser menor que 1
    if (tamanho < 1)
    {
        return TAMANHO_INVALIDO;
    }

    vetorPrincipal[posicao] = criaAux(tamanho);
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(Aux *vetorPrincipal[TAM], int posicao, int valor)
{
    posicao = getPosicaoNoVetor(posicao);

    if (posicao == -1)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    Aux *container = vetorPrincipal[posicao];

    if (container->qtd == container->tamanho)
    {
        return SEM_ESPACO;
    }
    else
    {
        insereElemento(container, valor);
        return SUCESSO;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(Aux *vetorPrincipal[TAM], int posicao)
{
    posicao = getPosicaoNoVetor(posicao);

    if (posicao == -1)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao]->qtd > 0)
    {
        Aux *container = vetorPrincipal[posicao];
        removeUltimoElemento(container);
        return SUCESSO;
    }
    else
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(Aux *vetorPrincipal[TAM], int posicao, int valor)
{
    posicao = getPosicaoNoVetor(posicao);

    if (posicao == -1)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    Aux *container = vetorPrincipal[posicao];

    if (encontraElemento(container, valor))
    {
        removeElemento(container, valor);
        return SUCESSO;
    }
    else
    {
        return NUMERO_INEXISTENTE;
    }
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int vetorAux[])
{
    posicao = getPosicaoNoVetor(posicao);

    if (posicao == -1)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    Aux *container = vetorPrincipal[posicao];
    copiaElementos(container, vetorAux, 0);

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int vetorAux[])
{

    int retornoGetDados = getDadosEstruturaAuxiliar(vetorPrincipal, posicao, vetorAux);

    if (retornoGetDados == SUCESSO)
    {
        int tamanho = vetorPrincipal[getPosicaoNoVetor(posicao)]->tamanho;
        ordenaVetor(vetorAux, tamanho);

        return SUCESSO;
    }
    else
    {
        return retornoGetDados;
    }
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(Aux *vetorPrincipal[TAM], int vetorAux[])
{
    int ultimaPosOcupada = 0;
    int algumVetor = 0;
    Aux *estruturaAtual;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i] == NULL)
        {
            continue;
        }

        // Detecta que estrutura principal não está vazia
        algumVetor = 1;

        estruturaAtual = vetorPrincipal[i];
        copiaElementos(estruturaAtual, vetorAux, ultimaPosOcupada);
        ultimaPosOcupada += estruturaAtual->qtd;
    }

    if (!algumVetor)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(Aux *vetorPrincipal[TAM], int vetorAux[])
{
    int qtdNumeros = 0;
    Aux *estruturaAtual;

    // Descobre total de números
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i])
        {
            estruturaAtual = vetorPrincipal[i];
            qtdNumeros += estruturaAtual->qtd;
        }
    }

    if (qtdNumeros == 0)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vetorAux);
    ordenaVetor(vetorAux, qtdNumeros);

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int novoTamanho)
{
    posicao = getPosicaoNoVetor(posicao);

    if (posicao == -1)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    Aux *container = vetorPrincipal[posicao];

    if (container->tamanho + novoTamanho <= 0)
    {
        return NOVO_TAMANHO_INVALIDO;
    }
    else
    {
        modificaTamanho(container, novoTamanho);
        return SUCESSO;
    }
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao)
{
    posicao = getPosicaoNoVetor(posicao);

    Aux *container = vetorPrincipal[posicao];
    return container->qtd;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}

int getPosicaoNoVetor(int inputPosicao)
{
    // Devolve posição como índice no vetor
    if (inputPosicao >= 1 && inputPosicao <= TAM)
    {
        return inputPosicao - 1;
    }
    else
    {
        return -1;
    }
}

void destruirEstruturasAuxiliares(Aux *vetorPrincipal[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i])
        {
            destroiAux(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}