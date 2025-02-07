// Testes para estrutura auxiliar (Aux)

#include <stdio.h>
#include <stdlib.h>

#include "EstruturaAux.h"

void auxCriado();
void auxCriadoComInput();
void auxCriadoComInputTamanhoIncorreto();
void auxCriadoComInputValoresIncorretos();
void elementoInserido();
void elementoNaoInserido();
void elementoRemovido();
void elementoNaoRemovido();
void tamanhoAumentado();
void tamanhoDiminuido();
void elementosCopiados();
void elementosCopiadosMeioDoVetor();
void elementoEncontrado();
void elementoNaoEncontrado();
void ultimoElementoRemovido();

int main()
{
    auxCriado();
    auxCriadoComInput();
    auxCriadoComInputTamanhoIncorreto();
    auxCriadoComInputValoresIncorretos();
    elementoInserido();
    elementoNaoInserido();
    elementoRemovido();
    elementoNaoRemovido();
    tamanhoAumentado();
    tamanhoDiminuido();
    elementosCopiados();
    elementosCopiadosMeioDoVetor();
    elementoEncontrado();
    elementoNaoEncontrado();
    ultimoElementoRemovido();
}

void auxCriado()
{
    int tamanho = 1;
    Aux *aux = NULL;
    aux = criaAux(tamanho);

    int sucesso = aux && aux->tamanho == 1 && aux->qtd == 0;
    printf("Auxiliar é criado: %d\n", sucesso);

    destroiAux(aux);
}

void auxCriadoComInput()
{
    char input[] = "1 10";
    Aux *aux = NULL;
    aux = criaAuxComInput(input);

    printf("Auxiliar é criado com input:\n");

    printf("\tCom sucesso: %d\n", aux != NULL);
    printf("\tCom tamanho correto: %d\n", aux->tamanho == 1);
    printf("\tCom quantidade correta de elementos: %d\n", aux->qtd == 1);
    printf("\tCom valor correto: %d\n", aux->head->valor == 10);

    destroiAux(aux);
}

void auxCriadoComInputTamanhoIncorreto()
{
    char input[] = "MIL 1 2 3";
    Aux *aux = NULL;
    aux = criaAuxComInput(input);

    printf("Auxiliar NÃO é criado com input se tamanho não for válido: %d\n", aux == NULL);

    destroiAux(aux);
}

void auxCriadoComInputValoresIncorretos()
{
    char input[] = "3 1 a b c 2 3 4";
    Aux *aux = NULL;
    aux = criaAuxComInput(input);

    printf("Auxiliar é criado com input com valores inválidos:\n");
    printf("\tIgnorando inválidos: %d\n", aux != NULL);
    printf("\tIgnorando excedentes: %d\n", aux->qtd == 3 && !aux->head->proximo->proximo->proximo);
}

void elementoInserido()
{
    Aux *aux = criaAux(1);
    int novoElemento = 5;
    insereElemento(aux, novoElemento);

    int sucesso = aux && aux->qtd == 1 && aux->head->valor == novoElemento;
    printf("Elemento é inserido no auxiliar não cheio: %d\n", sucesso);

    destroiAux(aux);
}

void elementoNaoInserido()
{
    Aux *aux = criaAux(1);
    int elemento = 5;
    insereElemento(aux, elemento);
    // Capacidade do aux atingida

    int novoElemento = 10;

    int sucesso = aux && aux->qtd == 1 && aux->head->valor == elemento;
    printf("Elemento não é inserido no auxiliar cheio: %d\n", sucesso);

    destroiAux(aux);
}

void elementoRemovido()
{
    // Aux com dois elementos de mesmo valor
    Aux *aux = criaAux(2);
    int elemento = 5;
    insereElemento(aux, elemento);
    insereElemento(aux, elemento);

    // Elemento removido apenas uma vez
    removeElemento(aux, elemento);

    int sucesso = aux &&
                  // Quantidade de elementos alterada
                  aux->qtd == 1 &&
                  // Head atualizado
                  aux->head->valor == elemento;
    printf("Elemento encontrado é removido: %d\n", sucesso);

    destroiAux(aux);
}

void elementoNaoRemovido()
{
    Aux *aux = criaAux(1);
    int elementoNoAux = 2;
    int elementoForaDoAux = 3;
    insereElemento(aux, elementoNoAux);

    removeElemento(aux, elementoForaDoAux);

    int sucesso = aux && aux->qtd == 1;
    printf("Tentativa de remoção não altera o auxiliar: %d\n", sucesso);

    destroiAux(aux);
}

void tamanhoAumentado()
{
    Aux *aux = criaAux(1);
    insereElemento(aux, 5);

    modificaTamanho(aux, 1);
    int novoElemento = 10;
    insereElemento(aux, novoElemento);

    int sucesso = aux->tamanho == 2 && aux->head->proximo->valor == novoElemento;
    printf("Tamanho do auxiliar é aumentado: %d\n", sucesso);

    destroiAux(aux);
}

void tamanhoDiminuido()
{
    Aux *aux = criaAux(1);
    insereElemento(aux, 5);

    modificaTamanho(aux, -1);

    int sucesso = aux->tamanho == 0;
    printf("Tamanho do auxiliar é diminuido: %d\n", sucesso);

    destroiAux(aux);
}

void elementosCopiados()
{
    Aux *aux = criaAux(3);
    insereElemento(aux, 1);
    insereElemento(aux, 2);
    insereElemento(aux, 3);

    int lista[3];
    copiaElementos(aux, lista, 3, 0);

    int sucesso = lista[0] == 1 && lista[1] == 2 && lista[2] == 3;
    printf("Elementos são copiados para um vetor: %d\n", sucesso);

    destroiAux(aux);
}

void elementosCopiadosMeioDoVetor()
{
    Aux *aux = criaAux(3);
    insereElemento(aux, 1);
    insereElemento(aux, 2);
    insereElemento(aux, 3);

    int lista[5];
    lista[0] = lista[1] = -1;
    copiaElementos(aux, lista, 5, 2);

    // Valores são adicionados a partir da posição 2
    int sucesso = lista[2] == 1 && lista[3] == 2 && lista[4] == 3
                  // Valores anteriores não são alterados
                  && lista[0] == -1 && lista[1] == -1;
    printf("Elementos são copiados para um vetor em uma posição diferente da inicial: %d\n", sucesso);

    destroiAux(aux);
}

void elementoEncontrado()
{
    Aux *aux = criaAux(1);
    insereElemento(aux, 3);

    Elemento *encontrado = encontraElemento(aux, 3);

    int sucesso = encontrado && encontrado->valor == 3;
    printf("Elemento é encontrado: %d\n", sucesso);

    destroiAux(aux);
}

void elementoNaoEncontrado()
{
    Aux *aux = criaAux(1);
    insereElemento(aux, 3);

    Elemento *encontrado = encontraElemento(aux, 100);

    int sucesso = !encontrado;
    printf("Elemento não é encontrado: %d\n", sucesso);

    destroiAux(aux);
}

void ultimoElementoRemovido()
{
    Aux *aux = criaAux(1);
    insereElemento(aux, 3);

    Elemento *removido = removeUltimoElemento(aux);

    int sucesso = removido && removido->valor == 3 && aux->qtd == 0;
    printf("Último elemento é removido: %d\n", sucesso);

    destroiAux(aux);
}