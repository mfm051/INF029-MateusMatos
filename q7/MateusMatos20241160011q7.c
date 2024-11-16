#include "MateusMatos20241160011q7.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char tabuleiro[3][3][2] = {'\0'};
    OpcaoJogador jogadores[2];

    jogadores[0] = obtemOpcaoJogador();
    if (jogadores[0].valido) {
        strcpy(tabuleiro[jogadores[0].linha][jogadores[0].coluna], "X");
        mostraTabuleiro(tabuleiro);
    } else
        printf("Eita\n");
}

void mostraTabuleiro(char tabuleiro[3][3][2])
{
    printf("\tA\tB\tC\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t", i + 1);

        for (int j = 0; j < 3; j++)
            printf("%c\t", tabuleiro[i][j][0]);

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

    if (('A' <= entrada[0] && entrada[0] <= 'C') && ('1' <= entrada[1] && entrada[1] <= '3')) {
        opcao.linha = entrada[0] - 'A'; // 'A' é linha 0 no tabuleiro
        opcao.coluna = entrada[1] - '1'; // '1' é coluna 0 no tabuleiro
        opcao.valido = 1;
    } else
        opcao.valido = 0;

    return opcao;
}