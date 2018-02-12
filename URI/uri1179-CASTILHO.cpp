#include <stdio.h>

void imprime(int v[], int n, int paridade) {
  int i;
  for (i = 0; i < n; i++)
    printf("%s[%d] = %d\n", paridade ? "par" : "impar", i, v[i]);
}

int main(void) {
  int i, n, qtd_i = 0, qtd_p = 0, par[10], imp[10];
  for (i = 0; i < 15; i++) {
    scanf("%d", &n);
    if (n & 1) {
      imp[qtd_i++] = n;
      if (qtd_i == 5) { imprime(imp, qtd_i, 0); qtd_i = 0; }
    } else {
      par[qtd_p++] = n;
      if (qtd_p == 5) { imprime(par, qtd_p, 1); qtd_p = 0; }
    }
  }
  imprime(imp, qtd_i, 0); imprime(par, qtd_p, 1);
  return 0;
}
