#include <stdio.h>

#define MAX 112345

typedef struct { char s, r; } bend_t;

char oposto(char c) { return c == '+' ? '-' : '+'; }

bend_t mapeia(bend_t atual, bend_t prox) {
  char cmp; bend_t ret;
  if (atual.r == 'x') {
    if (atual.s == '+') return prox;
    prox.s = oposto(prox.s);
    return prox;
  }
  cmp = (atual.r == 'z') ? 'y' : 'z';
  ret.r = 'x';
  if (prox.r == cmp) return atual;
  if (atual.s == prox.s) ret.s = '-';
  else ret.s = '+';
  return ret;
}

int main(void) {
  int l, i; bend_t mov[MAX], resp;
  while (scanf("%d", &l), l) {
    resp.s = '+'; resp.r = 'x';
    for (i = 0; i < l - 1; i++) {
      scanf(" %c%c", &mov[i].s, &mov[i].r);
      if (mov[i].s != 'N') resp = mapeia(resp, mov[i]);
    }
    printf("%c%c\n", resp.s, resp.r);
  }
  return 0;
}
