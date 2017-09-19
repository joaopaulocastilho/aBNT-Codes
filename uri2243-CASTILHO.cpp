#include<stdio.h>

#define MAX 51234

int altura[MAX], n;

int verifica(int tam, int i, int s) {
  int pm, k;
  pm = (i + s) / 2; //printf("pm = %d\n", pm);
  for (k = 0; k < tam; k++) {
    if (!(altura[pm - k] >= tam - k && altura[pm + k] >= tam - k)) return 0;
  }
  return 1;
}

int triangulo(int tam) {
  int i, j;
  for (i = 0, j = tam * 2; j <= n; i++, j++) {
    if(verifica(tam, i, j)) return 1;
  }
  return 0;
}

int main(void) {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &altura[i]);
  for (i = (int)(n / 2); i > 0; i--) {
    //printf("--------------------------------------------------------------------\n");
    if (triangulo(i)) { printf("%d\n", i); break; }
  }
  return 0;
}
