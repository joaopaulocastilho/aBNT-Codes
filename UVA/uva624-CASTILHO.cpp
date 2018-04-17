#include <stdio.h>

#define MAX 1123

int mu[MAX], resp[MAX], n, maior, tam, nt;

void bt(int i, int t, int pr, int tmp[]) {
  int j;
  if (i > nt) return;
  if (i < nt) {
    if (t + mu[i] <= n) {
      tmp[pr] = mu[i];
      bt(i + 1, t + mu[i], pr + 1, tmp);
    }
    bt(i + 1, t, pr, tmp);
  }
  if (t > maior) {
    tam = pr;
    maior = t;
    for (j = 0; j < pr; j++) resp[j] = tmp[j];
  }}

int main(void) {
  int i, tmp[MAX];
  while (scanf("%d %d", &n ,&nt) != EOF) {
    for (i = 0; i < nt; i++) scanf("%d", &mu[i]);
    maior = 0;
    bt(0, 0, 0, tmp);
    for (i = 0; i < tam; i++) printf("%d ", resp[i]);
    printf("sum:%d\n", maior);
  }
  return 0;
}
