#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 21
#define PIZZA 31

typedef struct { int tempo, qtd; }entrega;

int memo[MAX][PIZZA], n, p;
entrega e[MAX];

int pd(int i, int j) {
  if (i == n) return 0;
  //if (memo[i][j] != -1) return memo[i][j];
  if (j + e[i].qtd > p) return memo[i][j] = pd(i + 1, j);
  return memo[i][j] = max(pd(i + 1, j), pd(i + 1, j + e[i].qtd) + e[i].tempo);
}

int main(void) {
  int i;
  while (scanf("%d", &n), n) {
    memset(memo, -1, sizeof(memo));
    scanf("%d", &p);
    for (i = 0; i < n; i++) scanf("%d %d", &e[i].tempo, &e[i].qtd);
    printf("%d min.\n", pd(0, 0));
  }
  return 0;
}
