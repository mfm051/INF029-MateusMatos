#include "MateusMatos20241160011q7.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char tabuleiro[3][3] = {'\0'};
}

void mostraTabuleiro(char tabuleiro[3][3])
{
    printf("\tA\tB\tC\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t", i + 1);

        for (int j = 0; j < 3; j++)
            printf("%c\t", tabuleiro[i][j]);

        printf("\n");
    }
}

OpcaoJogador obtemOpcaoJogador()
{
    char entrada[4]; // 2 para opção, 1 para /n do fgets e 1 para \0
    OpcaoJogador opcao;

    printf("Posição no tabuleiro: ");
    fgets(entrada, 3, stdin);
    entrada[2] = '\0';

    // Normaliza letra da linha
    if (entrada[0] >= 'Z')
        entrada[0] -= ('a' - 'A');

    printf("Entrada lida: %s\n", entrada);

    if (('A' <= entrada[0] && entrada[0] <= 'C') &&
        ('1' <= entrada[1] && entrada[1] <= '3'))
    {
        opcao.linha = entrada[0] - 'A';  // 'A' é linha 0 no tabuleiro
        opcao.coluna = entrada[1] - '1'; // '1' é coluna 0 no tabuleiro
        opcao.valido = 1;
    }
    else
        opcao.valido = 0;

    return opcao;
}

int fimJogo(char tabuleiro[3][3])
{
    int tabuleiroCheio = 1;
    char linha[3], coluna[3];

    // Testa linhas e colunas
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            linha[j] = tabuleiro[i][j];
            coluna[j] = tabuleiro[j][i];

            if (tabuleiroCheio && !(linha[j] && coluna[j]))
                tabuleiroCheio = 0; // Atualiza tabuleiro cheio para falso ao encontrar nulo
        }

        if ((linha[0] && linha[0] == linha[1] && linha[1] == linha[2]) ||
            (coluna[0] && coluna[0] == coluna[1] && coluna[1] == coluna[2]))
            return 1;
    }

    // Testa diagonais
    if ((tabuleiro[0][0] && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) ||
        (tabuleiro[2][0] && tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2]))
        return 1;

    // Se nenhum teste passar, jogo encerra se tabuleiro cheio
    return tabuleiroCheio;
}