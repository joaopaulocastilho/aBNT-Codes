#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 11234
#define MAXT 112
#define is_letter(x) ((x) >= 'a' && (x) <= 'z')

int tabela[MAXT][MAXT];

int testa(int i, int j, int n) {
  int k, l, ret = 1;
  for (l = n - 1, k = 0; k < n; k++, l--)
    ret &= (tabela[i][k] == tabela[j][l] &&
            tabela[k][i] == tabela[l][j] &&
            tabela[i][k] == tabela[k][i]);
  return ret;
}

int msp(int n) {
  int i, ret;
  for (ret = 1, i = 0; i < n; i++)
    ret &= testa(i, (n - 1) - i, n);
  return ret;
}

int main(void) {
  int casos, nc, i, flag, raiz, j, k, tam, cont;
  char linha[MAX];
  scanf("%d ", &casos);
  for (nc = 1; nc <= casos; nc++) {
    printf("Case #%d:\n", nc);
    fgets(linha, MAX, stdin); tam = strlen(linha);
    for (flag = 1, cont = i = 0; i < tam; i++)
      if (is_letter(linha[i])) cont++;
    raiz = sqrt(cont);
    if (raiz * raiz != cont) flag = 0;
    for (k = i = 0; flag && i < raiz; i++)
      for (j = 0; j < raiz; ) {
        if (is_letter(linha[k])) { tabela[i][j] = linha[k]; j++; }
        k++;
      }
    if (flag && msp(raiz)) printf("%d\n", raiz);
    else printf("No magic :(\n");
  }
  return 0;
}
