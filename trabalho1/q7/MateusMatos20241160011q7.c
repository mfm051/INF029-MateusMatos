#include "MateusMatos20241160011q7.h"

#include <stdio.h>
#include <string.h>

int main()
{
    char tabuleiro[3][3] = {'\0'};
    OpcaoJogador jogadores[2];
    char simbolos[2] = {'X', 'O'};
    int rodada = 1;
    int iJogador;

    do
    {
        mostraTabuleiro(tabuleiro);
        iJogador = (rodada + 1) % 2; // Alterna entre jogador 1 (i = 0) e jogador 2 (i = 1)

        do
        {
            printf("Jogador %d (%c): ", iJogador + 1, simbolos[iJogador]);
            jogadores[iJogador] = obtemOpcaoJogador();
        } while (!jogadores[iJogador].valido || !posicaoLivre(tabuleiro, jogadores[iJogador]));

        tabuleiro[jogadores[iJogador].linha][jogadores[iJogador].coluna] = simbolos[iJogador];
        rodada++;
    } while (!fimJogo(tabuleiro));

    printf("Fim de jogo\n");
    mostraTabuleiro(tabuleiro);
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
    char linha, coluna;
    OpcaoJogador opcao;

    char entrada[4];
    fgets(entrada, 4, stdin);
    sscanf(entrada, "%c%c", &coluna, &linha);

    // Normaliza letra da coluna
    if (coluna >= 'Z')
        coluna -= ('a' - 'A');

    if (('A' <= coluna && coluna <= 'C') &&
        ('1' <= linha && linha <= '3'))
    {
        opcao.coluna = coluna - 'A'; // 'A' é coluna 0 no tabuleiro
        opcao.linha = linha - '1';   // '1' é linha 0 no tabuleiro
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

int posicaoLivre(char tabuleiro[3][3], OpcaoJogador posicao)
{
    return tabuleiro[posicao.linha][posicao.coluna] == '\0';
}
