#ifndef VELHAHEADER
#define VELHAHEADER

typedef struct OJ{
    int linha;
    int coluna;
    int valido; // 0: inválido, 1: válido
} OpcaoJogador;

void mostraTabuleiro(char tabuleiro[3][3][2]);
OpcaoJogador obtemOpcaoJogador();

#endif // VELHAHEADER
