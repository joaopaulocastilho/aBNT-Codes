#include <stdio.h>

#define MAX 112

int main(void) {
  int p, r, fila[MAX], vivo[MAX], i, j, qt, com, ac, caso = 0, resp = 0;
  while (scanf("%d %d", &p, &r), p) {
    caso++;
    for (i = 1; i <= p; i++) { scanf("%d", &fila[i]); vivo[i] = 1; }
    for (i = 0; i < r; i++) {
      scanf("%d %d", &qt, &com);
      for (j = 1; j <= p; j++) {
        if (!vivo[j]) continue;
        scanf("%d", &ac);
        if (ac != com) vivo[j] = 0;
      }
    }
    for (i = 1; i <= p; i++)
      if (vivo[i]) { resp = i; break; }
    printf("Teste %d\n%d\n\n", caso, fila[resp]);
  }
  return 0;
}
