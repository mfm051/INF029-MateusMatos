#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

#include "EstruturaVetores.h"

Aux *vetorPrincipal[TAM];

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
int criarEstruturaAuxiliar(int posicao, int tamanho)
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
int inserirNumeroEmEstrutura(int posicao, int valor)
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
int excluirNumeroDoFinaldaEstrutura(int posicao)
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
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
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
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
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
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retornoGetDados = getDadosEstruturaAuxiliar(posicao, vetorAux);

    if (retornoGetDados == SUCESSO)
    {
        int qtdElementos = vetorPrincipal[getPosicaoNoVetor(posicao)]->qtd;
        ordenaVetor(vetorAux, qtdElementos);

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
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int posAtual = 0;
    int algumVetor = 0;
    Aux *estruturaAtual;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i])
        {
            estruturaAtual = vetorPrincipal[i];
            if (estruturaAtual->qtd == 0)
                continue;

            // Detecta que estrutura principal não está vazia
            algumVetor = 1;

            copiaElementos(estruturaAtual, vetorAux, posAtual);

            posAtual += estruturaAtual->qtd;
        }
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
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
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

    getDadosDeTodasEstruturasAuxiliares(vetorAux);
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
int modificarTamanhoEstruturaAuxiliar(int posicao, int valorExtra)
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

    if (container->tamanho + valorExtra <= 0)
    {
        return NOVO_TAMANHO_INVALIDO;
    }
    else
    {
        modificaTamanho(container, valorExtra);
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
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao = getPosicaoNoVetor(posicao);

    if (posicao == -1)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao])
    {
        Aux *aux = vetorPrincipal[posicao];
        int qtd = aux->qtd > 0 ? aux->qtd : ESTRUTURA_AUXILIAR_VAZIA;
        return qtd;
    }
    else
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    int totalElementos = getQuantidadeTotalElementos();

    if (totalElementos == 0)
        return NULL;

    int elementos[totalElementos];
    getDadosDeTodasEstruturasAuxiliares(elementos);

    No *inicio = (No *)malloc(sizeof(No));
    inicio->conteudo = elementos[0];

    No *atual = inicio;

    for (int i = 1; i < totalElementos; i++)
    {
        atual->prox = (No *)malloc(sizeof(No));
        atual->prox->conteudo = elementos[i];

        atual = atual->prox;
    }

    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual = inicio;
    int posAtual = 0;

    while (atual)
    {
        vetorAux[posAtual] = atual->conteudo;
        posAtual++;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;
    No *removido;

    while (atual)
    {
        removido = atual;
        atual = atual->prox;
        free(removido);
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    for (int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i] = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    destruirEstruturasAuxiliares();
}

// Funções adicionadas pelo aluno

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

void destruirEstruturasAuxiliares()
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

/*
Retorno (int)
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/

int getQuantidadeTotalElementos()
{
    int qtdTotal = 0;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i])
        {
            qtdTotal += vetorPrincipal[i]->qtd;
        }
    }

    if (qtdTotal == 0)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else
    {
        return qtdTotal;
    }
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

void dobrar(int *x)
{
    *x *= 2;
}

void criarEstruturaAuxiliarComInput(char *input)
{
    /* Estrutura do input: POSIÇÃO TAMANHO NUM1 NUM2... */

    char *numStr; /* Representa string do número atual */
    char *fim;    /* Primeira posição não numérica de numStr */

    /* Encontra posição do auxiliar */
    numStr = strtok_r(input, " ", &input);
    int pos = (int)strtol(numStr, &fim, 10);

    /* Cancela se posição é inválida */
    if (fim == numStr || (pos < 1 || pos > 10))
        return;

    /* Encontra tamanho do auxiliar */
    numStr = strtok_r(input, " ", &input);
    int tam = (int)strtol(numStr, &fim, 10);

    /* Cancela se tamanho é inválido */
    if (fim == numStr || tam <= 0)
        return;

    /* Tamanho e posição válidos, procede com criação da estrutura */
    criarEstruturaAuxiliar(pos, tam);
    int num;

    while ((numStr = strtok_r(input, " ", &input)))
    {
        num = (int)strtol(numStr, &fim, 10);

        if (fim != numStr)
        {
            inserirNumeroEmEstrutura(pos, num);
        }
    }
}

void criarEstruturasComArquivo(FILE *arq)
{
    char numeros[10000];

    while (fgets(numeros, sizeof(numeros), arq))
    {
        /* Remove caractere de nova linha */
        numeros[strcspn(numeros, "\n")] = 0;

        criarEstruturaAuxiliarComInput(numeros);
    }
}

void imprimirEstruturasEmArquivo(FILE *arq)
{
    Aux *aux;
    Elemento *atual;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i])
        {
            aux = vetorPrincipal[i];

            fprintf(arq, "%d ", i + 1); /* Posição = i + 1 */
            fprintf(arq, "%d", aux->tamanho);

            atual = aux->head;

            if (atual)
                fprintf(arq, " ");

            while (atual)
            {
                fprintf(arq, "%d", atual->valor);

                if (atual->proximo)
                    fprintf(arq, " ");

                atual = atual->proximo;
            }

            fprintf(arq, "\n");
        }
    }
}