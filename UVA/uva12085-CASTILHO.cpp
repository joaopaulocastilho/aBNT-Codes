#include <stdio.h>

#define MAX 112345

int conta_digitos(int dig, int n) {
  int i, ndig, ret = 0, mul = 1, v[MAX], tmp;
  int va1[MAX], va2[MAX];
  tmp = n;
  for (i = 0; dig; i++) {
    va1[i] = dig % 10;
    va2[i] = n % 10;
    dig /= 10;
    n /= 10;
  }
  for (ndig = 0, i--; i; i--) {
    if (va1[i] != va2[i]) break;
  }
  ndig = i + 1;
  for (n = tmp, i = 0; i < ndig; i++) {
    v[i] = n % 10;
    n /= 10;
  }
  for (i = ndig - 1; i >= 0; i--) {
    ret *= mul;
    ret += v[i];
    mul = 10;
  }
  return ret;
}

int main(void) {
  int n, i, tel[MAX], ini, intervalo, caso = 1;
  while (scanf("%d", &n), n) {
    printf("Case %d:\n", caso); caso++;
    for (i = 0; i < n; i++) scanf("%d", &tel[i]);
    for (ini = i = 0; i < n - 1; i++) {
      if (tel[i] + 1!= tel[i + 1]) {
	intervalo = 0;
	if (ini != i)
	  intervalo = conta_digitos(tel[ini], tel[i]);
	printf("0%d", tel[ini]);
	if (intervalo) printf("-%d", intervalo);
	printf("\n");
	ini = i + 1;
      }
    }
    intervalo = 0;
    if (ini != i)
      intervalo = conta_digitos(tel[ini], tel[i]);
    printf("0%d", tel[ini]);
    if (intervalo) printf("-%d", intervalo);
    printf("\n\n"); 
  }
  return 0;
}
