#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"
#include "EstruturaAux.h"

void show_log(char *str);

void testeInserirSemNada();
void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeExcluir();
void testeExcluirNumeroEspecifico();
void testeListar();
void testeRetornarTodosNumeros();
void testeMudarTamanhoEstrutura();
// Testes adicionados pelo aluno
void testeObterQuantidadeTotalNumeros();
void testeDobrarNumero();
void testeCriarEstruturasComArquivo();
void testeImprimirEstruturasEmArquivo();

int main()
{
    testeInserirSemNada();
    testeCriarEstrutura();
    testeInserirComEstrutura();
    testeExcluir();
    testeExcluirNumeroEspecifico();
    testeListar();
    testeRetornarTodosNumeros();
    testeMudarTamanhoEstrutura();
    testeObterQuantidadeTotalNumeros();
    testeDobrarNumero();
    testeCriarEstruturasComArquivo();
    testeImprimirEstruturasEmArquivo();
}
int ligado = 1;
void show_log(char *str)
{
    if (ligado)
        printf("###%s###\n", str);
}

void testeInserirSemNada()
{
    Aux *vetorPrincipal[TAM] = {NULL};

    show_log("testeInserirSemNada()");
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, -2, 2) == POSICAO_INVALIDA);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 0, 2) == POSICAO_INVALIDA);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 11, 2) == POSICAO_INVALIDA);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeCriarEstrutura()
{
    Aux *vetorPrincipal[TAM] = {NULL};

    show_log("testeCriarEstrutura()");
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, -2, 5) == POSICAO_INVALIDA);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 0, 5) == POSICAO_INVALIDA);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 11, 5) == POSICAO_INVALIDA);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, -5) == TAMANHO_INVALIDO);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 0) == TAMANHO_INVALIDO);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeInserirComEstrutura()
{
    Aux *vetorPrincipal[TAM] = {NULL};
    criarEstruturaAuxiliar(vetorPrincipal, 2, 3);

    /*
    2 [ , , ]
    */

    show_log("testeInserirComEstrutura()");
    // ###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 4) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, -2) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 6) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 5) == SEM_ESPACO);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeExcluir()
{
    Aux *vetorPrincipal[TAM] = {NULL};
    criarEstruturaAuxiliar(vetorPrincipal, 2, 3);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, 4);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, -2);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, 6);

    /*
    2 [4,-2,6]
    */

    show_log("testeExcluir()");
    // ###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 0) == POSICAO_INVALIDA);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == ESTRUTURA_AUXILIAR_VAZIA);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeExcluirNumeroEspecifico()
{
    Aux *vetorPrincipal[TAM] = {NULL};
    criarEstruturaAuxiliar(vetorPrincipal, 9, 3);
    inserirNumeroEmEstrutura(vetorPrincipal, 9, 7);
    inserirNumeroEmEstrutura(vetorPrincipal, 9, 4);

    /*
    9 [ 4, , ]
    */

    show_log("testeExcluirNumeroEspecifico()");
    // ###  int excluirNumeroEspecificoDeEstrutura(int posicao, int valor); ###
    printf("%d ", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 9, 12) == NUMERO_INEXISTENTE);
    printf("%d ", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 9, 7) == SUCESSO);
    printf("%d ", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 9, 4) == SUCESSO);
    printf("%d", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 1, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeListar()
{
    Aux *vetorPrincipal[TAM] = {NULL};
    criarEstruturaAuxiliar(vetorPrincipal, 2, 2);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, 7);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, -9);

    /*
    2 [7, -9]
    */

    show_log("testeListar()");
    // ###  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); ###

    int vet[2];

    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 1, vet, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 11, vet, 2) == POSICAO_INVALIDA);
    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 2, vet, 2) == SUCESSO);
    printf("\n");

    printf("%d ", vet[0] == 7);
    printf("%d ", vet[1] == -9);
    printf("\n");

    printf("%d ", getDadosOrdenadosEstruturaAuxiliar(vetorPrincipal, 1, vet, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getDadosOrdenadosEstruturaAuxiliar(vetorPrincipal, 11, vet, 2) == POSICAO_INVALIDA);
    printf("%d ", getDadosOrdenadosEstruturaAuxiliar(vetorPrincipal, 2, vet, 2) == SUCESSO);
    printf("\n");

    printf("%d ", vet[0] == -9);
    printf("%d ", vet[1] == 7);
    printf("\n");

    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 2, vet, 2) == SUCESSO);
    printf("\n");

    printf("%d ", vet[0] == 7);
    printf("%d ", vet[1] == -9);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeRetornarTodosNumeros()
{
    Aux *vetorPrincipal[TAM] = {NULL};

    show_log("testeRetornarTodosNumeros()");
    int vet1[2];
    printf("%d ", getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet1, 2) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d ", getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet1, 2) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 8) == SUCESSO);
    printf("%d", inserirNumeroEmEstrutura(vetorPrincipal, 2, 0) == SUCESSO);
    printf("\n");

    /*
    2 [3,8,0]
    */

    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 5, 10) == SUCESSO);

    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 1) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 34) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 12) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 6) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 27) == SUCESSO);
    printf("%d", inserirNumeroEmEstrutura(vetorPrincipal, 5, -6) == SUCESSO);
    printf("\n");

    /*
    2 [3,8,0]
    5 [1,34,12,6,27,-6, , , , ]
    */

    int vet[9];

    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet, 9) == SUCESSO);

    printf("%d ", vet[0] == 3);
    printf("%d ", vet[1] == 8);
    printf("%d ", vet[2] == 0);
    printf("%d ", vet[3] == 1);
    printf("%d ", vet[4] == 34);
    printf("%d ", vet[5] == 12);
    printf("%d ", vet[6] == 6);
    printf("%d ", vet[7] == 27);
    printf("%d", vet[8] == -6);
    printf("\n");

    int vet2[9];

    printf("%d ", getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet2, 9) == SUCESSO);

    printf("%d ", vet2[0] == -6);
    printf("%d ", vet2[1] == 0);
    printf("%d ", vet2[2] == 1);
    printf("%d ", vet2[3] == 3);
    printf("%d ", vet2[4] == 6);
    printf("%d ", vet2[5] == 8);
    printf("%d ", vet2[6] == 12);
    printf("%d ", vet2[7] == 27);
    printf("%d", vet2[8] == 34);
    printf("\n");

    printf("%d ", getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet, 9) == SUCESSO);

    printf("%d ", vet[0] == 3);
    printf("%d ", vet[1] == 8);
    printf("%d ", vet[2] == 0);
    printf("%d ", vet[3] == 1);
    printf("%d ", vet[4] == 34);
    printf("%d ", vet[5] == 12);
    printf("%d ", vet[6] == 6);
    printf("%d ", vet[7] == 27);
    printf("%d", vet[8] == -6);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

/*
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
void testeMudarTamanhoEstrutura()
{
    Aux *vetorPrincipal[TAM] = {NULL};
    criarEstruturaAuxiliar(vetorPrincipal, 2, 3);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, 3);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, 8);
    inserirNumeroEmEstrutura(vetorPrincipal, 2, 0);

    /*
    2 [3,8,0]
    */

    show_log("testeMudarTamanhoEstrutura()");

    printf("%d ", modificarTamanhoEstruturaAuxiliar(vetorPrincipal, 2, -3) == NOVO_TAMANHO_INVALIDO);
    printf("%d ", modificarTamanhoEstruturaAuxiliar(vetorPrincipal, 2, -4) == NOVO_TAMANHO_INVALIDO);
    printf("%d ", modificarTamanhoEstruturaAuxiliar(vetorPrincipal, 11, 7) == POSICAO_INVALIDA);
    printf("%d ", modificarTamanhoEstruturaAuxiliar(vetorPrincipal, 0, 7) == POSICAO_INVALIDA);
    printf("%d", modificarTamanhoEstruturaAuxiliar(vetorPrincipal, 1, 7) == SEM_ESTRUTURA_AUXILIAR);
    printf("\n");

    int vet[1];

    // modificar para tamanho de 3 para 1
    printf("%d ", modificarTamanhoEstruturaAuxiliar(vetorPrincipal, 2, -2) == SUCESSO);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 2) == 1);
    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 2, vet, 1) == SUCESSO); // Vetor principal está sendo populado na posição 0 a partir daqui
    printf("%d", vet[0] == 3);
    printf("\n");

    /*
    2 [3]
    */

    // modificar para tamanho de 1 para 4
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(vetorPrincipal, 2, 3) == SUCESSO);

    /*
    2 [3, , , ]
    */

    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 2) == 1);
    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 2, vet, 1) == SUCESSO);
    printf("%d", vet[0] == 3);
    printf("\n");

    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 4) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, -2) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 6) == SUCESSO);

    /*
    2 [3, 4, -2, 6]
    */

    printf("%d", inserirNumeroEmEstrutura(vetorPrincipal, 2, 5) == SEM_ESPACO);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeObterQuantidadeTotalNumeros()
{
    Aux *vetorPrincipal[TAM] = {NULL};

    show_log("testeObterQuantidadeTotalNumeros()");

    printf("%d ", getQuantidadeTotalElementos(vetorPrincipal) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    criarEstruturaAuxiliar(vetorPrincipal, 1, 2);
    inserirNumeroEmEstrutura(vetorPrincipal, 1, 1);

    criarEstruturaAuxiliar(vetorPrincipal, 3, 2);
    inserirNumeroEmEstrutura(vetorPrincipal, 3, 1);
    inserirNumeroEmEstrutura(vetorPrincipal, 3, 2);

    /*
    1 [1, ]
    3 [1, 2]
    */

    printf("%d", getQuantidadeTotalElementos(vetorPrincipal) == 3);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
}

void testeDobrarNumero()
{
    int num = 5;
    int outroNum = 0;
    int maisUmNum = -1;

    show_log("testeDobrarNumero()");

    dobrar(&num);       // 5 => 10
    dobrar(&num);       // 10 => 20
    dobrar(&outroNum);  // 0 => 0
    dobrar(&maisUmNum); // -1 => -2

    printf("%d ", num == 20);
    printf("%d ", outroNum == 0);
    printf("%d", maisUmNum == -2);
    printf("\n");
}

void testeCriarEstruturasComArquivo()
{
    show_log("testeCriarEstruturasComArquivo()");

    /* Setup arquivo teste */
    FILE *arq = fopen("testeEstruturas", "w");
    fprintf(arq, "1 3 0 0 0\n"
                 "3 1\n"
                 "6 2 -1 2\n"
                 "10 5 1 2\n");
    fclose(arq);

    arq = fopen("testeEstruturas", "r");

    Aux *vetorPrincipal[10] = {NULL};

    criarEstruturasComArquivo(vetorPrincipal, arq);

    /*
    1 [0, 0, 0]
    3 [ ]
    6 [-1, 2]
    10 [1, 2, , , ]
    */

    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 1) == 3);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 3) == ESTRUTURA_AUXILIAR_VAZIA);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 4) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 5) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 6) == 2);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 7) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 8) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 9) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, 10) == 2);
    printf("\n");

    destruirEstruturasAuxiliares(vetorPrincipal);
    fclose(arq);
}

void testeImprimirEstruturasEmArquivo()
{
    show_log("testeImprimirEstruturasEmArquivo()");

    printf("Resultado do teste no arquivo testeEstruturas\n");
    printf("O arquivo deve conter:\n"
           "1 2 1 2\n"
           "2 1\n"
           "6 2 -1\n"
           "9 5 1 2\n");

    FILE *arq = fopen("testeEstruturas", "w");

    Aux *vetorPrincipal[TAM] = {NULL};

    criarEstruturaAuxiliar(vetorPrincipal, 1, 2);
    criarEstruturaAuxiliar(vetorPrincipal, 2, 1);
    criarEstruturaAuxiliar(vetorPrincipal, 6, 2);
    criarEstruturaAuxiliar(vetorPrincipal, 9, 5);

    inserirNumeroEmEstrutura(vetorPrincipal, 1, 1);
    inserirNumeroEmEstrutura(vetorPrincipal, 1, 2);
    inserirNumeroEmEstrutura(vetorPrincipal, 6, -1);
    inserirNumeroEmEstrutura(vetorPrincipal, 9, 1);
    inserirNumeroEmEstrutura(vetorPrincipal, 9, 2);

    /*
    1 [1, 2]
    2 [ ]
    6 [-1, ]
    9 [1, 2, , , ]
    */

    imprimirEstruturasEmArquivo(vetorPrincipal, arq);

    destruirEstruturasAuxiliares(vetorPrincipal);
    fclose(arq);
}