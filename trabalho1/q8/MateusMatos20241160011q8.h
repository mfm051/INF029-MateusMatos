#ifndef NAVALHEADER
#define NAVALHEADER

// Navios obrigatórios
#define QTDNAVIOS4 1
#define QTDNAVIOS3 1
#define QTDNAVIOS1 3
// Navios extras
#define QTDNAVIOS2 0

typedef struct Navio {
  int tamanho;
  // Coordenadas do navio [linha, coluna]
  int inicio[2];
  int fim[2];
} Navio;

void mostraTabuleiro(char tabuleiro[10][10]);
void inicializaTabuleiro(char tabuleiro[10][10]);
int navioValido(Navio navio, char tabuleiro[10][10]);

#endif // NAVALHEADER
