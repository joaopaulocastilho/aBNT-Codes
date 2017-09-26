#include<stdio.h>

int main(void) {
  int ant1 = 0, ant2 = 1, n, aux, i;
  scanf("%d", &n);
  printf("%d", ant1);
  if (n > 1) printf(" %d", ant2);
  for (i = 0; i < n - 2; i++) {
    printf(" %d", ant1 + ant2);
    aux = ant1;
    ant1 = ant2;
    ant2 = aux + ant2;
  }
  printf("\n");
  return 0;
}
