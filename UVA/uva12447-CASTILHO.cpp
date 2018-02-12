#include <stdio.h>
#include <string.h>

#define MAX 112

void ordena(int &n1, int &n2, int &n3) {
  int aux;
  if (n3 < n1 && n3 < n2) {
    aux = n1;
    n1 = n3;
    n3 = aux;
  } else if (n2 < n1 && n2 < n3) {
    aux = n1;
    n1 = n2;
    n2 = aux;
  }
  if (n3 < n2) {
    aux = n2;
    n2 = n3;
    n3 = aux;
  }
}

int main(void) {
  int a, b, c, x, y, i, aux, flag, deck[MAX], xa, ya;;
  while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y), a) {
    xa = x; ya = y;
    memset(deck, 0, sizeof(deck));
    deck[a] = deck[b] = deck[c] = deck[x] = deck[y] = 1;
    ordena(a, b, c);
    for (flag = i = 1; flag && i <= 52; i++) {
      if(deck[i]) continue;
      aux = i;
      ordena(x, y, aux);
      //printf("%d %d %d %d %d %d", a, b, c, x, y, aux);
      if (!(c > y && b > x)) { flag = 0; printf("%d\n", i); }
      x = xa; y = ya;
    }
    if (flag) printf("-1\n");
  }
  return 0;
}
