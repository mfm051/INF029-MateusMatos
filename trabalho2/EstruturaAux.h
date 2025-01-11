#ifndef AUX_H
#define AUX_H

// Estrutura "auxiliar" que abriga uma quantidade de inteiros
// determinada pelo usuário. Representada por uma lista ligada
// de elementos

typedef struct Elemento
{
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Aux
{
    Elemento *head;
    int tamanho;
    int qtd; // Total de elementos adicionados
} Aux;

Aux *criaAux(int tamanho);
void destroiAux(Aux *aux);
int insereElemento(Aux *aux, int valor);
void removeElemento(Aux *aux, int valor);
Elemento *encontraElemento(Aux *aux, int valor);
Elemento *removeUltimoElemento(Aux *aux);
void modificaTamanho(Aux *aux, int incremento);
void copiaElementos(Aux *aux, int *vetor, int tamanhoVetor, int posInicial);
Elemento *encontraUltimoElemento(Aux *aux);
Elemento *criaElemento(int valor);
// Funções auxiliares
void ordenaVetor(int *vetor, int tamanho);

#endif // AUX_H