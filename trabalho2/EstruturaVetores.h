#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

#include "EstruturaAux.h"

#define TAM 10

// enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
// as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
// as constantes do enums em sua inicialização vao representar o numero resultante da soma do valor da
// constante anterior mais 1, caso nao haja valor algum na primeira constante ela vai ser inicializada com 0
enum
{
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11,
    NOVO_TAMANHO_INVALIDO,
    NUMERO_INEXISTENTE,
    ESTRUTURA_AUXILIAR_VAZIA,
    TAMANHO_INVALIDO,
    SEM_ESPACO_DE_MEMORIA,
    POSICAO_INVALIDA,
    JA_TEM_ESTRUTURA_AUXILIAR,
    SEM_ESTRUTURA_AUXILIAR,
    SEM_ESPACO,
    SUCESSO
};

// Struct não utilizado
// Uma solução semelhante está presente em EstruturaAux.c/EstruturaAux.h

// typedef struct reg
// {
//     int conteudo;
//     struct reg *prox;
// } No;

int criarEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int tamanho);
int inserirNumeroEmEstrutura(Aux *vetorPrincipal[TAM], int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(Aux *vetorPrincipal[TAM], int posicao);
int excluirNumeroEspecificoDeEstrutura(Aux *vetorPrincipal[TAM], int posicao, int valor);
int getDadosEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int vetorAux[], int tamanhoVetorAux);
int getDadosOrdenadosEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int vetorAux[], int tamanhoVetorAux);
int getDadosDeTodasEstruturasAuxiliares(Aux *vetorPrincipal[TAM], int vetorAux[], int tamanhoVetorAux);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(Aux *vetorPrincipal[TAM], int vetorAux[], int tamanhoVetorAux);
int modificarTamanhoEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(Aux *vetorPrincipal[TAM], int posicao);

/*
    Funções não adicionadas pois estão contempladas na estrutura auxiliar:

    No *montarListaEncadeadaComCabecote();
    void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
    void destruirListaEncadeadaComCabecote(No **inicio);

*/

/*
    Funções não utilizadas, devido ao vetorPrincipal
    não ser um parâmetro global:

    void inicializar();
    void finalizar();
*/

void dobrar(int *x);

// Funções adicionadas pelo aluno
int getPosicaoNoVetor(int inputPosicao);
void destruirEstruturasAuxiliares(Aux *vetorPrincipal[TAM]);
int getQuantidadeTotalElementos(Aux *vetorPrincipal[TAM]);
void ordenaVetor(int *vetor, int tamanho);
void criarEstruturaAuxiliarComInput(Aux *vetorPrincipal[TAM], char *input);
void criarEstruturasComArquivo(Aux *vetorPrincipal[TAM], FILE *arq);
void imprimirEstruturasEmArquivo(Aux *vetorPrincipal[TAM], FILE *arq);

#endif // TRABALHO2_ESTRUTURAVETORES_H
