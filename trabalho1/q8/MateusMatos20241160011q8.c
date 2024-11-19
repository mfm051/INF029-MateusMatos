#include "MateusMatos20241160011q8.h"
#include <stdio.h>

int main() {
  char tabuleiroJ1[10][10];
  char tabuleiroJ2[10][10];
  inicializaTabuleiro(tabuleiroJ1);
  inicializaTabuleiro(tabuleiroJ2);

  mostraTabuleiro(tabuleiroJ1);
  printf("\n");
  mostraTabuleiro(tabuleiroJ2);
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

void inicializaTabuleiro(char tabuleiro[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      tabuleiro[i][j] = ' ';
  }
}

int navioValido(Navio navio, char tabuleiro[10][10]) {
  if ((navio.inicio[0] != navio.fim[0]) || (navio.inicio[1] != navio.fim[1])) {
    printf("Inválido! Navio deve estar na vertical ou na horizontal\n");
    return 0;
  }

  // Como navio não está na diagonal, uma das seguintes subtrações é zero
  int tamanho =
      (navio.fim[0] - navio.inicio[0]) + (navio.fim[1] - navio.inicio[1]);
  tamanho = tamanho < 0 ? -tamanho : tamanho;

  if (tamanho != navio.tamanho) {
    printf("Inválido! Navio tem tamanho %d\n", navio.tamanho);
    return 0;
  }

  for (int i = navio.inicio[0]; i <= navio.fim[0]; i++) {
    for (int j = navio.inicio[1]; j <= navio.fim[1]; j++) {
      if (tabuleiro[i][j] != ' ') {
        printf("Inválido! Posição ocupada\n");
        return 0;
      }
    }
  }

  return 1;
}
