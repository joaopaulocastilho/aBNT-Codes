#include <stdio.h>

#define MAX 112

int main(void) {
  int n, i, sol[MAX], ma, me, dma, dme, ima, ime;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &sol[i]);
  ma = me = sol[0];
  dma = 0; dme = n - 1; ima = 0; ime = 0;
  for (i = 1; i < n; i++) {
    if (sol[i] > ma) { ma = sol[i]; dma = i; ima = i; }
    if (sol[i] <= me) { me = sol[i]; dme = n - (i + 1); ime = i; }
  }
  printf("%d\n", dma + dme - (ima > ime));
  return 0;
}
