#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"
#include "container.h"

void show_log(char *str);

void testeInserirSemNada();
void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeExcluir();
void testeExcluirNumeroEspecifico();
void testeListar();
void testeRetornarTodosNumeros();
void testeMudarTamanhoEstrutura();
void testeListaEncadeada();
// Testes para container (estrutura auxiliar)
void containerCriado();
void elementoInserido();
void elementoNaoInserido();
void elementoRemovido();
void elementoNaoRemovido();
void tamanhoAumentado();
void elementosCopiados();
void elementosCopiadosMeioDoVetor();
void elementoEncontrado();
void elementoNaoEncontrado();
void ultimoElementoRemovido();

int main()
{
    inicializar();

    printf("\n\nTestes de integração estruturas principal/secundária\n\n");
    testeInserirSemNada();
    testeCriarEstrutura();
    testeInserirComEstrutura();
    testeExcluir();
    testeExcluirNumeroEspecifico();
    testeListar();
    testeRetornarTodosNumeros();
    /*testeMudarTamanhoEstrutura();
    testeListaEncadeada();*/

    printf("\n\nTestes de estrutura secundária (container)\n\n");
    containerCriado();
    elementoInserido();
    elementoNaoInserido();
    elementoRemovido();
    elementoNaoRemovido();
    tamanhoAumentado();
    elementosCopiados();
    elementosCopiadosMeioDoVetor();
    elementoEncontrado();
    elementoNaoEncontrado();
    ultimoElementoRemovido();

    finalizar();
}
int ligado = 1;
void show_log(char *str)
{
    if (ligado)
        printf("###%s###\n", str);
}

void testeInserirSemNada()
{
    Container *vetorPrincipal[TAM] = {NULL};

    show_log("testeInserirSemNada()");
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, -2, 2) == POSICAO_INVALIDA);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 0, 2) == POSICAO_INVALIDA);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 11, 2) == POSICAO_INVALIDA);
    printf("\n");
}

void testeCriarEstrutura()
{
    Container *vetorPrincipal[TAM] = {NULL};

    show_log("testeCriarEstrutura()");
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, -2, 5) == POSICAO_INVALIDA);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 0, 5) == POSICAO_INVALIDA);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 11, 5) == POSICAO_INVALIDA);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, -5) == TAMANHO_INVALIDO);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 0) == TAMANHO_INVALIDO);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
    printf("\n");
}

void testeInserirComEstrutura()
{
    Container *vetorPrincipal[TAM] = {NULL};

    show_log("testeInserirComEstrutura()");
    // ###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 4) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, -2) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 6) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 5) == SEM_ESPACO);
    printf("\n");
}

void testeExcluir()
{
    Container *vetorPrincipal[TAM] = {NULL};

    show_log("testeExcluir()");
    // ###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 4) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, -2) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 6) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 0) == POSICAO_INVALIDA);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == ESTRUTURA_AUXILIAR_VAZIA);
    printf("\n");
}

void testeExcluirNumeroEspecifico()
{
    Container *vetorPrincipal[TAM] = {NULL};

    show_log("testeExcluirNumeroEspecifico()");
    // ###  int excluirNumeroEspecificoDeEstrutura(int posicao, int valor); ###
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 9, 3) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 9, 7) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 9, 4) == SUCESSO);
    printf("%d ", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 9, 12) == NUMERO_INEXISTENTE);
    printf("%d ", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 9, 7) == SUCESSO);
    printf("%d ", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 9, 4) == SUCESSO);
    printf("%d ", excluirNumeroEspecificoDeEstrutura(vetorPrincipal, 1, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("\n");
}

void testeListar()
{
    Container *vetorPrincipal[TAM] = {NULL};

    show_log("testeListar()");
    // ###  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); ###
    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 2) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 7) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, -9) == SUCESSO);

    int vet[2];

    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 11, vet) == POSICAO_INVALIDA);
    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 2, vet) == SUCESSO);

    printf("%d ", vet[0] == 7);
    printf("%d ", vet[1] == -9);

    printf("%d ", getDadosOrdenadosEstruturaAuxiliar(vetorPrincipal, 1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d ", getDadosOrdenadosEstruturaAuxiliar(vetorPrincipal, 11, vet) == POSICAO_INVALIDA);
    printf("%d ", getDadosOrdenadosEstruturaAuxiliar(vetorPrincipal, 2, vet) == SUCESSO);

    printf("%d ", vet[0] == -9);
    printf("%d ", vet[1] == 7);

    printf("%d ", getDadosEstruturaAuxiliar(vetorPrincipal, 2, vet) == SUCESSO);

    printf("%d ", vet[0] == 7);
    printf("%d ", vet[1] == -9);

    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("%d ", excluirNumeroDoFinaldaEstrutura(vetorPrincipal, 2) == SUCESSO);
    printf("\n");
}

void testeRetornarTodosNumeros()
{
    Container *vetorPrincipal[TAM] = {NULL};

    show_log("testeRetornarTodosNumeros()");
    int vet1[2];
    printf("%d ", getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d ", getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 3) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 2, 8) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(vetorPrincipal, 2, 0) == SUCESSO);
    /*
2 [3,8,0]
*/

    printf("%d ", criarEstruturaAuxiliar(vetorPrincipal, 5, 10) == SUCESSO);

    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 1) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 34) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 12) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 6) == SUCESSO);
    printf("%d ", inserirNumeroEmEstrutura(vetorPrincipal, 5, 27) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(vetorPrincipal, 5, -6) == SUCESSO);
    /*
2 [3,8,0]
5 [1,34,12,6,27,-6, , , , ]
*/
    int vet[9];

    printf("%d ", getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet) == SUCESSO);

    printf("%d ", vet[0] == 3);
    printf("%d ", vet[1] == 8);
    printf("%d ", vet[2] == 0);
    printf("%d ", vet[3] == 1);
    printf("%d ", vet[4] == 34);
    printf("%d ", vet[5] == 12);
    printf("%d ", vet[6] == 6);
    printf("%d ", vet[7] == 27);
    printf("%d\n", vet[8] == -6);

    int vet2[9];

    printf("%d ", getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet2) == SUCESSO);

    printf("%d ", vet2[0] == -6);
    printf("%d ", vet2[1] == 0);
    printf("%d ", vet2[2] == 1);
    printf("%d ", vet2[3] == 3);
    printf("%d ", vet2[4] == 6);
    printf("%d ", vet2[5] == 8);
    printf("%d ", vet2[6] == 12);
    printf("%d ", vet2[7] == 27);
    printf("%d\n", vet2[8] == 34);

    printf("%d ", getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vet) == SUCESSO);

    printf("%d ", vet[0] == 3);
    printf("%d ", vet[1] == 8);
    printf("%d ", vet[2] == 0);
    printf("%d ", vet[3] == 1);
    printf("%d ", vet[4] == 34);
    printf("%d ", vet[5] == 12);
    printf("%d ", vet[6] == 6);
    printf("%d ", vet[7] == 27);
    printf("%d\n", vet[8] == -6);
}
/*
2 [3,8,0]
5 [1,34,12,6,27,-6, , , , ]
*/

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
// void testeMudarTamanhoEstrutura()
// {
//     show_log("testeMudarTamanhoEstrutura()");
//     int vet[1];
//     printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -3) == NOVO_TAMANHO_INVALIDO);
//     printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -4) == NOVO_TAMANHO_INVALIDO);
//     printf("%d\n", modificarTamanhoEstruturaAuxiliar(11, 7) == POSICAO_INVALIDA);
//     printf("%d\n", modificarTamanhoEstruturaAuxiliar(0, 7) == POSICAO_INVALIDA);
//     printf("%d\n", modificarTamanhoEstruturaAuxiliar(1, 7) == SEM_ESTRUTURA_AUXILIAR);

//     // modificar para tamanho de 3 para 1
//     printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -2) == SUCESSO);
//     printf("%d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
//     printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
//     printf("%d\n", vet[0] == 3);

//     // modificar para tamanho de 1 para 4
//     printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, 3) == SUCESSO);
//     printf("%d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
//     printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
//     printf("%d\n", vet[0] == 3);

//     printf("%d\n", inserirNumeroEmEstrutura(2, 4) == SUCESSO);
//     printf("%d\n", inserirNumeroEmEstrutura(2, -2) == SUCESSO);
//     printf("%d\n", inserirNumeroEmEstrutura(2, 6) == SUCESSO);
//     printf("%d\n", inserirNumeroEmEstrutura(2, 5) == SEM_ESPACO);
// }

/*
2 [3,4,-2,6]
5 [1,34,12,6,27,-6, , , , ]
*/

// void testeListaEncadeada()
// {
//     show_log("testeListaEncadeada()");
//     int vet[10];
//     No *inicio = montarListaEncadeadaComCabecote();
//     getDadosListaEncadeadaComCabecote(inicio, vet);

//     printf("%d\n", vet[0] == 3);
//     printf("%d\n", vet[1] == 4);
//     printf("%d\n", vet[2] == -2);
//     printf("%d\n", vet[3] == 6);
//     printf("%d\n", vet[4] == 1);
//     printf("%d\n", vet[5] == 34);
//     printf("%d\n", vet[6] == 12);
//     printf("%d\n", vet[7] == 6);
//     printf("%d\n", vet[8] == 27);
//     printf("%d\n", vet[9] == -6);

//     destruirListaEncadeadaComCabecote(&inicio);

//     printf("%d\n", inicio == NULL);
// }

// Testes para container (estrutura auxiliar)

void containerCriado()
{
    int tamanho = 1;
    Container *container = NULL;
    container = criaContainer(tamanho);

    int sucesso = container && container->tamanho == 1 && container->qtd == 0;
    printf("Container é criado: %d\n", sucesso);
}

void elementoInserido()
{
    Container *container = criaContainer(1);
    int novoElemento = 5;
    insereElemento(container, novoElemento);

    int sucesso = container && container->qtd == 1 && container->head->valor == novoElemento;
    printf("Elemento é inserido no container não cheio: %d\n", sucesso);
}

void elementoNaoInserido()
{
    Container *container = criaContainer(1);
    int elemento = 5;
    insereElemento(container, elemento);
    // Capacidade do container atingida

    int novoElemento = 10;

    int sucesso = container && container->qtd == 1 && container->head->valor == elemento;
    printf("Elemento não é inserido no container cheio: %d\n", sucesso);
}

void elementoRemovido()
{
    // Container com dois elementos de mesmo valor
    Container *container = criaContainer(2);
    int elemento = 5;
    insereElemento(container, elemento);
    insereElemento(container, elemento);

    // Elemento removido apenas uma vez
    removeElemento(container, elemento);

    int sucesso = container &&
                  // Quantidade de elementos alterada
                  container->qtd == 1 &&
                  // Head atualizado
                  container->head->valor == elemento;
    printf("Elemento encontrado é removido do container: %d\n", sucesso);
}

void elementoNaoRemovido()
{
    Container *container = criaContainer(1);
    int elementoNoContainer = 2;
    int elementoForaDoContainer = 3;
    insereElemento(container, elementoNoContainer);

    removeElemento(container, elementoForaDoContainer);

    int sucesso = container && container->qtd == 1;
    printf("Tentativa de remoção não altera o container: %d\n", sucesso);
}

void tamanhoAumentado()
{
    Container *container = criaContainer(1);
    insereElemento(container, 5);

    aumentaTamanho(container, 1);
    int novoElemento = 10;
    insereElemento(container, novoElemento);

    int sucesso = container->tamanho == 2 && container->head->proximo->valor == novoElemento;
    printf("Tamanho do conteiner é aumentado: %d\n", sucesso);
}

void elementosCopiados()
{
    Container *container = criaContainer(3);
    insereElemento(container, 1);
    insereElemento(container, 2);
    insereElemento(container, 3);

    int lista[3];
    copiaElementos(container, lista, 0);

    int sucesso = lista[0] == 1 && lista[1] == 2 && lista[2] == 3;
    printf("Elementos são copiados para um vetor: %d\n", sucesso);
}

void elementosCopiadosMeioDoVetor()
{
    Container *container = criaContainer(3);
    insereElemento(container, 1);
    insereElemento(container, 2);
    insereElemento(container, 3);

    int lista[5];
    lista[0] = lista[1] = -1;
    copiaElementos(container, lista, 2);

    // Valores são adicionados a partir da posição 2
    int sucesso = lista[2] == 1 && lista[3] == 2 && lista[4] == 3
                  // Valores anteriores não são alterados
                  && lista[0] == -1 && lista[1] == -1;
    printf("Elementos são copiados para um vetor em uma posição diferente da inicial: %d\n", sucesso);
}

void elementoEncontrado()
{
    Container *container = criaContainer(1);
    insereElemento(container, 3);

    Elemento *encontrado = encontraElemento(container, 3);

    int sucesso = encontrado && encontrado->valor == 3;
    printf("Elemento é encontrado: %d\n", sucesso);
}

void elementoNaoEncontrado()
{
    Container *container = criaContainer(1);
    insereElemento(container, 3);

    Elemento *encontrado = encontraElemento(container, 100);

    int sucesso = !encontrado;
    printf("Elemento não é encontrado: %d\n", sucesso);
}

void ultimoElementoRemovido()
{
    Container *container = criaContainer(1);
    insereElemento(container, 3);

    Elemento *removido = removeUltimoElemento(container);

    int sucesso = removido && removido->valor == 3 && container->qtd == 0;
    printf("Último elemento é removido: %d\n", sucesso);
}