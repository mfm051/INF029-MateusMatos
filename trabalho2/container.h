// Estrutura "auxiliar" que abriga uma quantidade de inteiros
// determinada pelo usuário
typedef struct Container
{
    int *elementos;
    int tamanho;
    int qtd; // Total de elementos adicionados
} Container;

Container *criaContainer(int tamanho);
void insereElemento(Container *container, int elemento);