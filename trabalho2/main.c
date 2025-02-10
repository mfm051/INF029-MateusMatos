#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

const char BACKUP_ESTRUTURAS[] = "estruturas";

enum
{
    SAIR = 1,
    CRIAR_ESTRUTURA,
    LISTAR_ESTRUTURA,
    AUMENTAR_TAMANHO,
    LISTAR_TODAS_ESTRUTURAS,
    INSERIR_ELEMENTO,
    EXCLUIR_ELEMENTO,
    LISTAR_TODOS_NUMEROS,
    DOBRAR_NUMERO
};

void printMenu()
{
    printf("\nDigite a opção desejada\n");
    printf("%d - Sair\n", SAIR);
    printf("%d - Criar estrutura\n", CRIAR_ESTRUTURA);
    printf("%d - Listar números de estrutura\n", LISTAR_ESTRUTURA);
    printf("%d - Aumentar tamanho de estrutura\n", AUMENTAR_TAMANHO);
    printf("%d - Listar todas as estruturas\n", LISTAR_TODAS_ESTRUTURAS);
    printf("%d - Inserir número\n", INSERIR_ELEMENTO);
    printf("%d - Excluir número\n", EXCLUIR_ELEMENTO);
    printf("%d - Listar todos os números\n", LISTAR_TODOS_NUMEROS);
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
    FILE *estruturas;

    estruturas = fopen(BACKUP_ESTRUTURAS, "r");

    if (estruturas)
    {
        criarEstruturasComArquivo(vetorPrincipal, estruturas);
        printf("\nEstruturas recuperadas com sucesso\n");
        fclose(estruturas);
    }

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

            estruturas = fopen(BACKUP_ESTRUTURAS, "w");
            if (estruturas)
            {
                imprimirEstruturasEmArquivo(vetorPrincipal, estruturas);
                printf("\nEstruturas salvas com sucesso\n");
                fclose(estruturas);
            }

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
                    char opcaoUsuario[5];
                    printf("Fazer listagem ordenada? [s/n]: ");
                    fgets(opcaoUsuario, sizeof(opcaoUsuario), stdin);
                    printf("\n");

                    if (opcaoUsuario[0] == 's')
                    {
                        ordenaVetor(vetorAux, qtd);
                    }

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

        case AUMENTAR_TAMANHO:
        {
            printf("Informe a posição da estrutura: ");
            int pos = getNumero();
            printf("\n");

            printf("Informe o quanto quer aumentar a estrutura: ");
            int valorExtra = getNumero();
            printf("\n");

            ret = modificarTamanhoEstruturaAuxiliar(vetorPrincipal, pos, valorExtra);

            if (ret == SUCESSO)
            {
                printf("Tamanho modificado com sucesso\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura auxiliar\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posição inválida\n");
            }
            else if (ret == NOVO_TAMANHO_INVALIDO)
            {
                printf("Valor inválido. Estrutura deve ter tamanho maior que zero\n");
            }
            break;
        }

        case LISTAR_TODAS_ESTRUTURAS:
        {
            int qtdAtual;

            for (int pos = 1; pos <= TAM; pos++)
            // Começando do número 1, pois representa posição como o usuário vê
            {
                printf("[%d] ", pos);

                qtdAtual = getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, pos);

                if (qtdAtual == SEM_ESTRUTURA_AUXILIAR)
                {
                    printf("Sem estrutura auxiliar");
                }
                else
                {
                    int tamanho = vetorPrincipal[pos - 1]->tamanho;
                    printf("(tamanho %d) => ", tamanho);

                    if (qtdAtual == ESTRUTURA_AUXILIAR_VAZIA)
                    {
                        printf("Sem elementos");
                    }
                    else
                    {
                        int vetorAux[qtdAtual];
                        ret = getDadosEstruturaAuxiliar(vetorPrincipal, pos, vetorAux, qtdAtual);

                        for (int i = 0; i < qtdAtual; i++)
                        {
                            printf("%d", vetorAux[i]);
                            if (i + 1 != qtdAtual)
                            {
                                printf(", ");
                            }
                        }
                    }
                }
                printf("\n");
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

        case LISTAR_TODOS_NUMEROS:
        {
            int qtdTotal = getQuantidadeTotalElementos(vetorPrincipal);

            if (qtdTotal == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS)
            {
                printf("Não há números adicionados\n");
                break;
            }

            int vetorAux[qtdTotal];
            ret = getDadosDeTodasEstruturasAuxiliares(vetorPrincipal, vetorAux, qtdTotal);

            char opcaoUsuario[5];
            printf("Fazer listagem ordenada? [s/n]: ");
            fgets(opcaoUsuario, sizeof(opcaoUsuario), stdin);
            printf("\n");

            if (opcaoUsuario[0] == 's')
            {
                ordenaVetor(vetorAux, qtdTotal);
            }

            // imprimir para os dados para o usuário
            for (int i = 0; i < qtdTotal; i++)
            {
                printf("%d", vetorAux[i]);
                if (i + 1 < qtdTotal)
                {
                    printf(", ");
                }
            }
            printf("\n");

            break;
        }

        case DOBRAR_NUMERO:
        { // dobrar
            // ler um numero
            int valor;
            char entrada[50];

            printf("Informe um valor: ");
            fgets(entrada, sizeof(entrada), stdin);
            sscanf(entrada, "%d\n", &valor);
            printf("\n");

            // passar para um funcao (void dobrar(...)) que recebe o numero e dobra (EstruturaVetores.c)
            dobrar(&valor);

            printf("%d\n", valor);

            break;
        }

        default:
        {
            printf("opcao inválida\n");
        }
        }
    }

    destruirEstruturasAuxiliares(vetorPrincipal);

    return 0;
}
