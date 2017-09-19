#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 212
#define INF 1123456789
#define valido(x, y) ((x) >= 0 && (x) < (y))

int G[MAX][MAX], h, l, comp;
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

void dfs(int i, int j) {
  int u, aux = G[i][j], ni, nj;
  G[i][j] = -1; comp++;
  for (u = 0; u < 4; u++) {
    ni = i + di[u]; nj = j + dj[u];
    if (valido(ni, h) && valido(nj, l) && G[ni][nj] != -1 &&
        G[ni][nj] == aux)
      dfs(ni, nj);
  }}

int main(void) {
  int i, j, resp;
  scanf("%d %d", &h, &l);
  for (i = 0; i < h; i++) for (j = 0; j < l; j++) scanf("%d", &G[i][j]);
  for (resp = INF, i = 0; i < h; i++)
    for (j = 0; j < l; j++)
      if (G[i][j] != -1) {
        comp = 0; dfs(i, j);
        resp = min(resp, comp);
      }
  printf("%d\n", resp);
  return 0;
}
