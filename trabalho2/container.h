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
int insereElemento(Container *container, int valor);
void removeElemento(Container *container, int valor);
void aumentaTamanho(Container *container, int qtdNovosElementos);
int *obtemElementosOrdenados(Container *container);
Elemento *encontraUltimoElemento(Container *container);
Elemento *criaElemento(int valor);