#include <stdio.h>

void mostraTabuleiro(char tabuleiro[10][10]);
void inicializaTabuleiro(char tabuleiro[10][10]);

int main() {
  char tabuleiro[10][10];
  inicializaTabuleiro(tabuleiro);
  mostraTabuleiro(tabuleiro);
}

void mostraTabuleiro(char tabuleiro[10][10]) {
  for (int i = 0; i < 10; i++) {
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
