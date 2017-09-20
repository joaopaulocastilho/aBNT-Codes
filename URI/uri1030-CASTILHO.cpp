#include<stdio.h>

int nf(int a, int b) {
  if (a == 1) return 0;
  return (nf(a - 1, b) + b) % a;
}

int main(void) {
  int n, k, nc, i;
  scanf("%d", &nc);
  for (i = 1; i <= nc; i++) {
    scanf("%d %d", &n, &k);
    printf("Case %d: %d\n", i, nf(n, k) + 1);
  }
  return 0;
}
