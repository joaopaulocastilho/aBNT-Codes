#include <stdio.h>
#include <string.h>

#define MAX 112

char linha[MAX];

int prox_str(int i) {
  int ret;
  if (linha[i + 2] == 'X') ret = 10;
  else ret = linha[i + 2] - '0';
  if (linha[i + 4] == 'X') ret += 10;
  else if (linha[i + 4] == '/') ret = 10;
  else ret += linha[i + 4] - '0';
  return ret;
}

int prox_squ(int i) {
  if (linha[i + 2] == 'X') return 10;
  return linha[i + 2] - '0';
}

int eh_num(char c) {
  if (c >= '0' && c <= '9') return 1;
  return 0;
}

int main(void) {
  int atual, jogada[MAX], resp, i, pts, next;
  while (fgets(linha, MAX, stdin)) {
    if (strcmp("Game Over\n", linha) == 0) return 0;
    for (next = atual = i = 0, pts = 1; atual < 10; i += 2, atual++) {
      if (linha[i] == 'X') {
        jogada[atual] = 10 + (atual == 9 ? 0 : prox_str(i));
        if (atual == 9) next = 1;
      }
      else {
        pts = linha[i] - '0';
        if (eh_num(linha[i + 2])) pts += linha[i + 2] - '0';
        else {
          pts = 10 + (atual == 9 ? 0 : prox_squ(i + 2));
          if (atual == 9) next = 2;
        }
        jogada[atual] = pts;
        i += 2;
      }
    }
    if (next == 1) {
      if (linha[i] == 'X') {
        pts = 10;
        if (linha[i + 2] == 'X') pts += 10;
        else pts += linha[i + 2] - '0';
        jogada[atual++] = pts;
      } else {
        pts = linha[i] - '0';
        if (eh_num(linha[i + 2])) pts += linha[i + 2] - '0';
        else pts = 10;
        jogada[atual++] = pts;
      }
    } else if (next == 2) {
      if (linha[i] == 'X') jogada[atual++] = 10;
      else jogada[atual++] = linha[i] - '0';
    }
    for (i = resp = 0; i < atual; i++) resp += jogada[i];
    printf("%d\n", resp);
  }
  return 0;
}
