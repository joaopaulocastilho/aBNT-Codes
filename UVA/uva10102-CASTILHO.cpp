#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAX 1123
#define MAX1 1123456
#define INF 112345678

typedef struct { int x, y; }coord;

coord c[MAX1];

int distEuc(int xa, int ya, int xb, int yb) {
  return (abs(xa - xb) + abs(ya - yb));
}

int main(void) {
  int qtd, x, y, n, resp, menor, i, j, k, m, q[MAX][MAX];
  char ca;
  while (scanf("%d", &m) != EOF) {
    for (qtd = i = 0; i < m; i++) {
      getchar();
      for (j = 0; j < m; j++) {
        scanf("%c", &ca);
        n = ca - '0'; q[i][j] = n;
        if (q[i][j] == 1) { c[qtd].x = i; c[qtd++].y = j; }
      }
    }
    for (resp = i = 0; i < qtd; i++) {
      x = c[i].x; y = c[i].y;
      for (menor = INF, j = 0; j < m; j++)
        for (k = 0; k < m; k++)
          if (q[j][k] == 3 && distEuc(j, k, x, y) < menor)
            menor = distEuc(j, k, x, y);
      resp = max(resp, menor);
    }
    printf("%d\n", resp);
  }
  return 0;
}
