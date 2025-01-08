#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

#include "container.h"

#define TAM 10

// enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
// as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
// as constantes do enum em sua inicialização vao representar o numero resultante da soma do valor da
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

typedef struct reg
{
    int conteudo;
    struct reg *prox;
} No;

int criarEstruturaAuxiliar(Container *vetorPrincipal[TAM], int posicao, int tamanho);
int inserirNumeroEmEstrutura(Container *vetorPrincipal[TAM], int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(Container *vetorPrincipal[TAM], int posicao);
int excluirNumeroEspecificoDeEstrutura(Container *vetorPrincipal[TAM], int posicao, int valor);
int getDadosEstruturaAuxiliar(Container *vetorPrincipal[TAM], int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(Container *vetorPrincipal[TAM], int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);

void inicializar();
void finalizar();
void dobrar(int *x);

int getPosicaoNoVetor(int inputPosicao);

#endif // TRABALHO2_ESTRUTURAVETORES_H
