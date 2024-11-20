#include "MateusMatos20241160011q8.h"
#include <stdio.h>
#include <unistd.h>

int main() {
  Jogador jogadores[2];
  int tiro;

  printf("Montagem dos mapas:\n");

  printf("--Jogador 1--\n");
  setupJogador(&jogadores[0]);
  alertaTrocaJogador();
  printf("--Jogador 2--\n");
  setupJogador(&jogadores[1]);
  alertaTrocaJogador();

  int rodada = 1;
  int iAtual, iAdv;
  Coordenadas posTiro;
  do {
    // Obtem os índices do jogador atual e do seu oponente
    iAtual = (rodada + 1) % 2;
    iAdv = (rodada + 2) % 2;

    printf("Vez do jogador %d atirar\n\n", iAtual + 1);
    do {
      mostraTabuleiro(ADVERSARIO, jogadores[iAdv].tabuleiro);
      posTiro = obtemCoordenadas();
      tiro = atira(posTiro, jogadores[iAdv].tabuleiro);

      if (tiro == TIROCERTO)
        jogadores[iAdv].posRestantes--;

      if (jogadores[iAdv].posRestantes == 0)
        break;
    } while (tiro == TIROINVALIDO || tiro == TIROCERTO);

    mostraTabuleiro(ADVERSARIO, jogadores[iAdv].tabuleiro);

    if (jogadores[iAdv].posRestantes == 0)
      break;
    else {
      sleep(1);
      printf("\n\n\n");
      rodada++;
    }
  } while ((jogadores[0].posRestantes != 0) &&
           (jogadores[1].posRestantes != 0));

  // O jogador da última rodada é o vencedor
  printf("Jogador %d é o vencedor da partida\n", iAtual + 1);
}

void setupJogador(Jogador *jogador) {
  // Inicializa tabuleiro com posições vazias
  for (int i = 0; i < MAXTAB; i++) {
    for (int j = 0; j < MAXTAB; j++)
      jogador->tabuleiro[i][j] = ' ';
  }
  mostraTabuleiro(DONO, jogador->tabuleiro);
  // Define índice de navios como -1 (nenhum navio adicionado);
  jogador->iNavios = -1;
  // Posiciona navios
  int qtdNavios4 = 1;
  int qtdNavios3 = 1;
  int qtdNavios1 = 3;
  int qtdNavios2 = 0;

  posicionaNavios(1, 4, jogador);
  posicionaNavios(1, 3, jogador);
  if (qtdNavios4 + qtdNavios3 + qtdNavios1 != MAXNAVIOS) {
    qtdNavios2 = MAXNAVIOS - (qtdNavios4 + qtdNavios3 + qtdNavios1);
    posicionaNavios(qtdNavios2, 2, jogador);
  }
  posicionaNavios(3, 1, jogador);
  // Adiciona total de casas ocupadas pelos navios
  jogador->posRestantes =
      qtdNavios4 * 4 + qtdNavios3 * 3 + qtdNavios2 * 2 + qtdNavios1;
}

void mostraTabuleiro(int codigoJogador, char tabuleiro[MAXTAB][MAXTAB]) {
  char simbolo;
  int i, j;

  for (i = 'A'; i < ('A' + MAXTAB); i++) {
    if (i == 'A')
      printf("\t");
    printf(" %c \t", i);
  }
  printf("\n");
  for (i = 0; i < MAXTAB; i++) {
    printf("%d\t", i + 1);

    for (j = 0; j < MAXTAB; j++) {
      simbolo = tabuleiro[i][j];
      // Oculta navios de adversário
      if (simbolo == 'N' && codigoJogador == ADVERSARIO)
        simbolo = ' ';

      printf("[%c]", simbolo);

      if (j != 9)
        printf("\t");
    }
    printf("\n");
  }
}

void marcaTabuleiro(Coordenadas inicio, Coordenadas fim, char simbolo,
                    char tabuleiro[MAXTAB][MAXTAB]) {
  for (int i = inicio.linha; i <= fim.linha; i++) {
    for (int j = inicio.coluna; j <= fim.coluna; j++)
      tabuleiro[i][j] = simbolo;
  }
}

int navioValido(Navio navio, char tabuleiro[MAXTAB][MAXTAB]) {
  if ((navio.inicio.linha != navio.fim.linha) &&
      (navio.inicio.coluna != navio.fim.coluna)) {
    printf("Inválido! Navio deve estar na vertical ou na horizontal\n");
    return 0;
  }

  // Como navio não está na diagonal, o seu tamanho é obtido pela distância
  // na vertical ou na horizontal
  int distanciaNavio = (navio.fim.linha - navio.inicio.linha) +
                       (navio.fim.coluna - navio.inicio.coluna);
  if (distanciaNavio < 0)
    distanciaNavio = -distanciaNavio;

  if (distanciaNavio + 1 != navio.tamanho) {
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
    printf("Informe a posição (ex.: A1, B10..): ");
    fgets(entrada, 10, stdin);
    sscanf(entrada, "%c%d", &coluna, &linha);

    if (coluna >= 'a' && coluna <= 'z')
      coluna -= ('a' - 'A');
  } while ((coluna < 'A' || coluna > 'A' + MAXTAB - 1) ||
           (linha < 1 || linha > MAXTAB));

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

      // Um jogador malvado pode posicionar o navio de baixo para cima
      // ou da direita para esquerda
      if ((navio.inicio.linha > navio.fim.linha) ||
          (navio.inicio.coluna > navio.fim.coluna)) {
        Coordenadas temp = navio.inicio;
        navio.inicio = navio.fim;
        navio.fim = temp;
      }
    } while (!navioValido(navio, jogador->tabuleiro));

    marcaTabuleiro(navio.inicio, navio.fim, 'N', jogador->tabuleiro);
    mostraTabuleiro(DONO, jogador->tabuleiro);
  }
}

int atira(Coordenadas posTiro, char tabuleiro[MAXTAB][MAXTAB]) {
  switch (tabuleiro[posTiro.linha][posTiro.coluna]) {
  case 'N': {
    tabuleiro[posTiro.linha][posTiro.coluna] = 'O';
    return TIROCERTO;
  }
  case ' ': {
    tabuleiro[posTiro.linha][posTiro.coluna] = 'X';
    return TIROERRADO;
  }
  default: {
    printf("Tiro inválido! Tente novamente\n");
    return TIROINVALIDO;
  }
  }
}

void alertaTrocaJogador() {
  for (int i = 0; i < 250; i++)
    printf(".\n");
  printf("Novo jogador! Não vale olhar...\n");
  sleep(1);
}
