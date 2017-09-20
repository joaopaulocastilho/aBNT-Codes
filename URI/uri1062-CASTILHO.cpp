#include<stdio.h>

#define MAX 1123

int main(void) {
  int n, ordem[MAX], pilha[MAX], topo, next, i, first = 1;
  while (scanf("%d", &n), n) {
    while (scanf("%d", &ordem[0]), ordem[0]) {
      for (i = 1; i < n; i++) scanf("%d", &ordem[i]);
      for (next = 0, topo = 0, i = 1; i <= n; i++) {
        pilha[topo++] = i;
        while (topo - 1 >= 0 && next >= 0 &&
               pilha[topo - 1] == ordem[next]) { topo--; next++; }
      }
      printf("%s\n", (topo == 0) ? "Yes" : "No");
    }
    printf("\n");
  }
  return 0;
}
