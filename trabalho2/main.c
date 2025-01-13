#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

enum
{
    SAIR = 1,
    CRIAR_ESTRUTURA,
    INSERIR_ELEMENTO,
    EXCLUIR_ELEMENTO,
    LISTAR_ESTRUTURA,
    DOBRAR_NUMERO
};

// void dobrar(int *x);

void printMenu()
{
    printf("\nDigite a opção desejada\n");
    printf("%d - Sair\n", SAIR);
    printf("%d - Criar estrutura\n", CRIAR_ESTRUTURA);
    printf("%d - Inserir elemento\n", INSERIR_ELEMENTO);
    printf("%d - Excluir elemento de estrutura\n", EXCLUIR_ELEMENTO);
    printf("%d - Listar uma estrutura\n", LISTAR_ESTRUTURA);
    printf("%d - Dobrar Numero\n", DOBRAR_NUMERO);
    printf("=> ");
}

int getNumero()
{
    char entradaUsuario[50];
    int num;

    fgets(entradaUsuario, sizeof(entradaUsuario), stdin);
    sscanf(entradaUsuario, "%d\n", &num);

    return num;
}

int main()
{
    Aux *vetorPrincipal[TAM] = {NULL};

    // inicializar();
    int op;
    int sair = 0;
    int ret;

    while (!sair)
    {
        printMenu();
        op = getNumero();
        printf("\n");
        switch (op)
        {
        case SAIR:
        {
            sair = 1;
            // finalizar();
            break;
        }

        case CRIAR_ESTRUTURA:
        {
            printf("Informe a posição da nova estrutura (entre 1 e 10): ");
            int pos = getNumero();
            printf("\n");

            printf("Informe o tamanho da estrutura (deve ser maior que 0): ");
            int tamanho = getNumero();
            printf("\n");

            ret = criarEstruturaAuxiliar(vetorPrincipal, pos, tamanho);

            if (ret == SUCESSO)
            {
                printf("Criado com sucesso\n");
            }
            else if (ret == JA_TEM_ESTRUTURA_AUXILIAR)
            {
                printf("Posição já tem estrutura auxiliar\n");
            }
            else if (ret == TAMANHO_INVALIDO)
            {
                printf("Tamanho inválido. Deve ser maior que 0\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posição inválida. Deve ser um número entre 1 e 10\n");
            }
            break;
        }

        case INSERIR_ELEMENTO:
        {
            printf("Informe a posição da estrutura (entre 1 e 10): ");
            int pos = getNumero();
            printf("\n");

            printf("Informe o número a ser inserido: ");
            int num = getNumero();
            printf("\n");

            ret = inserirNumeroEmEstrutura(vetorPrincipal, pos, num);
            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso\n");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem espaço\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posição inválida. Deve ser um número entre 1 e 10\n");
            }
            break;
        }

        case EXCLUIR_ELEMENTO:
        {
            printf("Informe posição para exclusão (entre 1 e 10): ");
            int pos = getNumero();
            printf("\n");

            printf("Informe valor a ser excluído: ");
            int valor = getNumero();
            printf("\n");

            ret = excluirNumeroEspecificoDeEstrutura(vetorPrincipal, pos, valor);
            if (ret == SUCESSO)
            {
                printf("Excluído com sucesso\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar\n");
            }
            else if (ret == NUMERO_INEXISTENTE)
            {
                printf("Número inexistente na estrutura\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posição inválida. Deve ser um número entre 1 e 10\n");
            }
            break;
        }

        case LISTAR_ESTRUTURA:
        {
            printf("Informe a posição da estrutura a ser listada (entre 1 e 10): ");
            int pos = getNumero();
            printf("\n");

            int qtd = getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, pos);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posição inválida\n");
            }
            else if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
            {
                printf("Estrutura vazia\n");
            }
            else if (qtd == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar\n");
            }
            else
            { // existe elemento
                int vetorAux[qtd];

                ret = getDadosEstruturaAuxiliar(vetorPrincipal, pos, vetorAux, qtd);

                if (ret == SUCESSO)
                {
                    // imprimir para os dados para o usuário
                    for (int i = 0; i < qtd; i++)
                    {
                        printf("%d", vetorAux[i]);
                        if (i + 1 < qtd)
                        {
                            printf(", ");
                        }
                    }
                    printf("\n");
                }
            }
            break;
        }

            // case 10:
            // { // dobrar
            //   // ler um numero
            //   // int valor;
            //   // scanf("%i", &valor);

            //     // dobrar(&valor);

            //     // // passar para um funcao (void dobrar(...)) que recebe o numero e dobra (EstruturaVetores.c)

            //     // printf("%i", valor);

            //     // break;
            // }

        default:
        {
            printf("opcao inválida\n");
        }
        }
    }

    return 0;
}
