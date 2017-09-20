#include<stdio.h>
#include<stdlib.h>

#define MAX 112

int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }

int main(void) {
  int inst, n, m, resp, i, bloco[MAX];
  scanf("%d", &inst);
  while (inst--) {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &bloco[i]);
    qsort(bloco, n, sizeof(int), &cmp);
    //for (i = 0; i < n; i++) printf("%d ", bloco[i]);
    for (resp = i = 0; m; i++) {
      while (bloco[i] <= m) { m -= bloco[i]; resp++; }
    }
    printf("%d\n", resp);
  }
  return 0;
}
