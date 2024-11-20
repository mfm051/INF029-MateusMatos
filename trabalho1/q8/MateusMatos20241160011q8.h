#ifndef NAVALHEADER
#define NAVALHEADER

#define MAXNAVIOS 5
#define MAXTAB 10

#define DONO 1
#define ADVERSARIO 2

#define TIROCERTO 1
#define TIROERRADO 2
#define TIROINVALIDO 3

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
  char tabuleiro[MAXTAB][MAXTAB];
  int posRestantes;
} Jogador;

// O tabuleiro é exibido de forma diferente se
// jogador for dono dele ou não (codigoJogador)
void mostraTabuleiro(int codigoJogador, char tabuleiro[MAXTAB][MAXTAB]);
void marcaTabuleiro(Coordenadas inicio, Coordenadas fim, char simbolo,
                    char tabuleiro[MAXTAB][MAXTAB]);
void setupJogador(Jogador *jogador);
int navioValido(Navio navio, char tabuleiro[MAXTAB][MAXTAB]);
Coordenadas obtemCoordenadas();
void posicionaNavios(int qtd, int tamNavio, Jogador *jogador);
// A função atirar altera o tabuleiro adversário
// e retorna TIROCERTO, TIROERRADO ou TIROINVALIDO
int atira(Coordenadas posTiro, char tabuleiro[MAXTAB][MAXTAB]);
void alertaTrocaJogador();
#endif // NAVALHEADER
