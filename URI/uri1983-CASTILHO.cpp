#include <stdio.h>

int main(void) {
  int i, n, idm, ida;
  double maior = 0.0, atual;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %lf", &ida, &atual);
    if (atual > maior) { idm = ida; maior = atual; }
  }
  if (maior < 8) printf("Minimum note not reached\n");
  else printf("%d\n", idm);
  return 0;
}
