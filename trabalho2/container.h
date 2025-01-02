// Estrutura "auxiliar" que abriga uma quantidade de inteiros
// determinada pelo usuário. Representada por uma lista ligada
// de elementos

typedef struct Elemento
{
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Container
{
    Elemento *head;
    int tamanho;
    int qtd; // Total de elementos adicionados
} Container;

Container *criaContainer(int tamanho);
void insereElemento(Container *container, int valor);
Elemento *encontraUltimoElemento(Container *container);
Elemento *criaElemento(int valor);