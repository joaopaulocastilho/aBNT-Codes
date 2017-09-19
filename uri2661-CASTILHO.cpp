#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define MAX 1000001

typedef long long ll;

int PI[MAX], pi;
ll n, fat[MAX];

void crivo(int n) {
  int i, j, primo, raiz;
  PI[0] = 2; pi = 1;
  for (i = 3; i <= n; i++) {
    raiz = sqrt(i); primo = 1;
    for (j = 0; primo && j < pi && PI[j] <= raiz; j++)
      if (i % PI[j] == 0) primo = 0;
    if (primo) PI[pi++] = i;
  }}

ll numFatores(ll n) {
  ll qtdFat = 0, flag;
  ll id_pf = 0, pf = PI[0];
  while (pf * pf <= n) {
    flag = 0;
    while (n % pf == 0) { n /= pf; flag = 1; }
    if (flag) qtdFat++;
    pf = PI[++id_pf];
  }
  if (n != 1) qtdFat++;
  return qtdFat;
}

ll calculaFat(ll n) {
  if (fat[n] != -1) return fat[n];
  if (n == 0) return fat[n] = 1;
  return fat[n] = n * calculaFat(n - 1);
}

ll comb(int n, int p) {
  ll maior, menor, num = 1, den;
  if (n == p) return 1;
  maior = max(p, (n - p));
  menor = min(p, (n - p));
  while (n > maior) { num *= n; n--; }
  den = calculaFat(menor);
  return num / den;
}

ll calcDespojado(ll nfat) {
  int i;
  ll ret = 0;
  for (i = 2; i <= nfat; i++) ret += comb(nfat, i);
  return ret;
}

int main(void) {
  ll resp, nfat;
  memset(fat, -1, sizeof(fat));
  crivo(MAX);
  scanf("%lld", &n);
  nfat = numFatores(n);
  resp = calcDespojado(nfat);
  printf("%lld\n", resp);
  return 0;
}
