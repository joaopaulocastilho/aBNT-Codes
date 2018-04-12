#include <stdio.h>

typedef long long ll;

int di[] = { 1, 0, -1, 0 };
int dj[] = { 0, -1, 0, 1 };

int main(void) {
  int sz, i, j, sentido, passo, k;
  ll p, cont;
  while (scanf("%d %lld", &sz, &p), sz) {
    passo = 1;
    for (k = sentido = 0, cont = 1, i = j = (sz + 1) / 2; cont < p; ) {
      i += passo * di[sentido]; j += passo * dj[sentido];
      cont += passo;
      if (cont >= p) break;
      k++;
      if (k == 2) { k = 0; passo++; }
      sentido = (sentido + 1) % 4;
    }
    while (cont != p) {
      i -= di[sentido]; j -= dj[sentido];
      cont--;
    }
    printf("Line = %d, column = %d.\n", i, j);
  }
  return 0;
}
