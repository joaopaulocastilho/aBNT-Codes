#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 2123
#define INF 1123456789

int a[MAX];

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int torna1(int a, int b, int cont) {
  int pa;
  if (a == 1 || b == 1) return cont;
  if (a % b == 0 || b % a == 0) return INF;
  pa = gcd(a, b);
  if (a > b) return torna1(pa, b, cont + 1);
  return torna1(a, pa, cont + 1);
}

int main(void) {
  int n, i, flag = 1, resp = 0, qtd;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    flag &= (a[i] != 1);
    resp += (a[i] == 1);
  }
  if (flag) qtd = INF;
  for (i = 0; flag && i < n - 1; i++)
    qtd = min(qtd, torna1(a[i], a[i + 1], 0));
  if (flag)
    printf("%d\n", (qtd == INF) ? -1 : n + qtd - 1);
  else
    printf("%d\n", n - resp);
  return 0;
}
