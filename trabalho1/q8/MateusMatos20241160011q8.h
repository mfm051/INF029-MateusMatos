#ifndef NAVALHEADER
#define NAVALHEADER

#define MAXNAVIOS 5

typedef struct Coordenadas {
  int linha;
  int coluna;
  int valido; // 0: inválido, 1: válido
} Coordenadas;

typedef struct Navio {
  int tamanho;
  Coordenadas inicio;
  Coordenadas fim;
} Navio;

typedef struct Jogador {
  Navio navios[MAXNAVIOS];
  int iNavios;
  char tabuleiro[10][10];
  int posRestantes;
} Jogador;

void mostraTabuleiro(char tabuleiro[10][10]);
void marcaTabuleiro(Coordenadas inicio, Coordenadas fim, char simbolo,
                    char tabuleiro[10][10]);
void setupJogador(Jogador *jogador);
int navioValido(Navio navio, char tabuleiro[10][10]);
Coordenadas obtemCoordenadas();
void posicionaNavios(int qtd, int tamNavio, Jogador *jogador);

#endif // NAVALHEADER
