#include <stdio.h>
#include <string.h>

#define MAX 512
#define TAB 8
//#define DEBUG
#define eh_num(x) ((x) >= '0' && (x) <= '9')

int ataques[TAB][TAB], tabuleiro[TAB][TAB];
int direi[] = { -1, 1, -1, 1, 0, 0, 1, -1 };
int djrei[] = { -1, -1, 1, 1, 1, -1, 0, 0 };
int dicavalo[] = { -2, -1, -2, -1, 2, 1, 2, 1 };
int djcavalo[] = { 1, 2, -1, -2, 1, 2, -1, -2 };

int valido(int x, int y) {
  if (x >= 0 && x < TAB && y >= 0 && y < TAB) return 1;
  return 0;
}

void torre(int i, int j) {
  int k, flag;
  for (flag = 1, k = 1; flag; k++) {
    if (valido(i + k, j) && tabuleiro[i + k][j] == 0) ataques[i + k][j] = 1;
    else flag = 0;
  }
  for (flag = 1, k = -1; flag; k--) {
    if (valido(i + k, j) && tabuleiro[i + k][j] == 0) ataques[i + k][j] = 1;
    else flag = 0;
  }
  for (flag = 1, k = 1; flag; k++) {
    if (valido(i, j + k) && tabuleiro[i][j + k] == 0) ataques[i][j + k] = 1;
    else flag = 0;
  }
  for (flag = 1, k = -1; flag; k--) {
    if (valido(i, j + k) && tabuleiro[i][j + k] == 0) ataques[i][j + k] = 1;
    else flag = 0;
  }}

void bispo(int i, int j) {
  int k, l, flag;
  for (flag = 1, k = l = 1; flag; k++, l++) {
    if (valido(i + k, j + l) && tabuleiro[i + k][j + l] == 0) ataques[i + k][j + l] = 1;
    else flag = 0;
  }
  for (flag = 1, k = l = -1; flag; k--, l--) {
    if (valido(i + k, j + l) && tabuleiro[i + k][j + l] == 0) ataques[i + k][j + l] = 1;
    else flag = 0;
  }
  for (flag = 1, k = 1, l = -1; flag; k++, l--) {
    if (valido(i + k, j + l) && tabuleiro[i + k][j + l] == 0) ataques[i + k][j + l] = 1;
    else flag = 0;
  }
  for (flag = 1, k = -1, l = 1; flag; k--, l++) {
    if (valido(i + k, j + l) && tabuleiro[i + k][j + l] == 0) ataques[i + k][j + l] = 1;
    else flag = 0;
  }}

void preenche(int i, int j, char peca) {
  int k;
  if (peca == 'k' || peca == 'K') {
    for (k = 0; k < 8; k++)
      if (valido(i + direi[k], j + djrei[k]))
        ataques[i + direi[k]][j + djrei[k]] = 1;
  } else if (peca == 'n' || peca == 'N') {
    for (k = 0; k < 8; k++)
      if (valido(i + dicavalo[k], j + djcavalo[k]))
        ataques[i + dicavalo[k]][j + djcavalo[k]] = 1;
  } else if (peca == 'r' || peca == 'R') torre(i, j);
  else if (peca == 'b' || peca == 'B') bispo(i, j);
  else if (peca == 'q' || peca == 'Q') {
    torre(i, j); bispo(i, j);
  } else if (peca == 'p') {
    if (valido(i + 1, j + 1)) ataques[i + 1][j + 1] = 1;
    if (valido(i + 1, j - 1)) ataques[i + 1][j - 1] = 1;
  } else if (peca == 'P') {
    if (valido(i - 1, j + 1)) ataques[i - 1][j + 1] = 1;
    if (valido(i - 1, j - 1)) ataques[i - 1][j - 1] = 1;
  }
}

int main(void) {
  int pos, cont, i, j, resp;
  char linha[MAX];
  while (fgets(linha, MAX, stdin)) {
    memset(tabuleiro, 0, sizeof(tabuleiro));
    memset(ataques, 0, sizeof(ataques));
    for (i = j = pos = cont = 0; linha[pos] != '\n'; pos++) {
      if (eh_num(linha[pos])) j += linha[pos] - '0';
      else if (linha[pos] == '/') { i++; j = 0; }
      else { tabuleiro[i][j] =  linha[pos]; j++; }
    }
    for (i = 0; i < TAB; i++)
      for (j = 0; j < TAB; j++)
        if (tabuleiro[i][j] != '\0') preenche(i, j, tabuleiro[i][j]);
    for (resp = i = 0; i < TAB; i++)
      for (j = 0; j < TAB; j++) resp += (tabuleiro[i][j] == 0 && ataques[i][j] == 0);
    printf("%d\n", resp);
#ifdef DEBUG
    for (i = 0; i < TAB; i++) {
      for (j = 0; j < TAB; j++) printf("%d", ataques[i][j]);
      printf("\n");
    }
#endif
  }
  return 0;
}
