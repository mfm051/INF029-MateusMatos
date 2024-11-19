#include "MateusMatos20241160011q8.h"
#include <stdio.h>

int main() {
  Jogador j1, j2;

  setupJogador(&j1);
  setupJogador(&j2);
}

void setupJogador(Jogador *jogador) {
  // Inicializa tabuleiro com posições vazias
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      jogador->tabuleiro[i][j] = ' ';
  }
  mostraTabuleiro(jogador->tabuleiro);
  // Define índice de navios como -1 (nenhum navio adicionado);
  jogador->iNavios = -1;
  // Posiciona navios
  int qtdNavios4 = 1;
  int qtdNavios3 = 1;
  int qtdNavios1 = 3;
  int qtdNavios2 = 0;

  posicionaNavios(1, 4, jogador);
  posicionaNavios(1, 3, jogador);
  posicionaNavios(3, 1, jogador);
  if (qtdNavios4 + qtdNavios3 + qtdNavios1 != MAXNAVIOS) {
    qtdNavios2 = MAXNAVIOS - (qtdNavios4 + qtdNavios3 + qtdNavios1);
    posicionaNavios(qtdNavios2, 2, jogador);
  }
  // Adiciona total de casas ocupadas pelos navios
  jogador->posRestantes =
      qtdNavios4 * 4 + qtdNavios3 * 3 + qtdNavios2 * 2 + qtdNavios1;
}

void mostraTabuleiro(char tabuleiro[10][10]) {
  printf("\t A \t B \t C \t D \t E \t F \t G \t H \t I \t J \n");

  for (int i = 0; i < 10; i++) {
    printf("%d\t", i + 1);

    for (int j = 0; j < 10; j++) {
      printf("[%c]", tabuleiro[i][j]);

      if (j != 9)
        printf("\t");
    }
    printf("\n");
  }
}

void marcaTabuleiro(Coordenadas inicio, Coordenadas fim, char simbolo,
                    char (*tabuleiro)[10]) {
  for (int i = inicio.linha; i <= fim.linha; i++) {
    for (int j = inicio.coluna; j <= fim.coluna; j++)
      tabuleiro[i][j] = simbolo;
  }
}

int navioValido(Navio navio, char tabuleiro[10][10]) {
  if ((navio.inicio.linha != navio.fim.linha) &&
      (navio.inicio.coluna != navio.fim.coluna)) {
    printf("Inválido! Navio deve estar na vertical ou na horizontal\n");
    return 0;
  }

  // Como navio não está na diagonal, o seu tamanho é obtido pela distância
  // na vertical ou na horizontal
  int tamanho = 1 + (navio.fim.linha - navio.inicio.linha) +
                (navio.fim.coluna - navio.inicio.coluna);
  if (tamanho < 0)
    tamanho = -tamanho;

  if (tamanho != navio.tamanho) {
    printf("Inválido! Navio tem tamanho %d\n", navio.tamanho);
    return 0;
  }

  for (int i = navio.inicio.linha; i <= navio.fim.linha; i++) {
    for (int j = navio.inicio.coluna; j <= navio.fim.coluna; j++) {
      if (tabuleiro[i][j] != ' ') {
        printf("Inválido! Posição ocupada\n");
        return 0;
      }
    }
  }

  return 1;
}

Coordenadas obtemCoordenadas() {
  char entrada[10];
  char coluna;
  int linha;

  do {
    printf("Informe coluna e linha (ex.: A1, B10..): ");
    fgets(entrada, 10, stdin);
    sscanf(entrada, "%c%d", &coluna, &linha);

    if (coluna >= 'a' && coluna <= 'z')
      coluna -= ('a' - 'A');
  } while ((coluna < 'A' || coluna > 'J') || (linha < 1 || linha > 10));

  Coordenadas coords;
  coords.coluna = coluna - 'A';
  coords.linha = linha - 1;

  return coords;
}

void posicionaNavios(int qtd, int tamNavio, Jogador *jogador) {
  Coordenadas coordsInicio, coordsFim;
  Navio navio;

  printf("Posicione seus navios de tamanho %d\n", tamNavio);

  for (int i = 0; i < qtd; i++) {
    printf("Navios restantes: %d\n", qtd - i);

    jogador->iNavios++; // Atualiza índice de navios
    navio = jogador->navios[jogador->iNavios];
    navio.tamanho = tamNavio;

    do {
      printf("Posição inicial do navio\n");
      coordsInicio = obtemCoordenadas();
      navio.inicio = coordsInicio;

      if (tamNavio == 1)
        navio.fim = coordsInicio;
      else {
        printf("Posição final do navio\n");
        coordsFim = obtemCoordenadas();
        navio.fim = coordsFim;
      }
    } while (!navioValido(navio, jogador->tabuleiro));

    marcaTabuleiro(navio.inicio, navio.fim, 'N', jogador->tabuleiro);
    mostraTabuleiro(jogador->tabuleiro);
  }
}
