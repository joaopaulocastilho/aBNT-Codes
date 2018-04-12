#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 212345

int main(void) {
  int n, p, a, v[MAX], ini, fim, resp = 0, menor, maior, i, total;
  char c;
  scanf("%d %d %d ", &n, &p, &a);
  for (i = 0; i < n; i++) { scanf("%c", &c); v[i] = (c == '.'); }
  v[n] = 0;
  for (ini = fim = 0; fim <= n; ) {
    if (v[fim]) fim++;
    else {
      total = fim - ini;
      if (p > a) {
        maior = p; menor = a;
        p -= min(p, (int)ceil((double)total / 2.));
        a -= min(a, total / 2);
      } else {
        maior = a; menor = p;
        a -= min(a, (int)ceil((double)total / 2.));
        p -= min(p, total / 2);
      }
      resp += min(maior, (int)ceil((double)total / 2.));
      resp += min(menor, total / 2);
      ini = fim + 1;
      fim++;
    }}
  printf("%d\n", resp);
  return 0;
}
