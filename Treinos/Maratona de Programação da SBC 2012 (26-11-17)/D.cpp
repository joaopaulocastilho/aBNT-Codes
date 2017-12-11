#include <stdio.h>

#define MAX 11234

int main(void) {
  int n, i, j, notas[MAX], soma, resp, media;
  while (scanf("%d", &n) != EOF) {
    for (resp = 1, soma= i = 0; i < n; i++) { scanf("%d", &notas[i]); soma += notas[i]; }
    if (soma % n) resp = -1;
    for (media = soma / n, i = 0, j = n - 1; resp != -1 && i < j; ) {
      if (notas[i] == media) { i++; continue; }
      if (notas[j] == media) { j--; continue; }
      notas[i]++; notas[j]--; resp++;
    }
    printf("%d\n", resp);
  }
  return 0;
}
