#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXC 51

int LG[MAXC][MAXC], dg[MAXC], seen[MAXC], resp;
int d[MAXC], low[MAXC], tempo;

void dfs(int u, int p) {
  int i, v, nf = 0;
  seen[u] = 1;
  d[u] = low[u] = tempo++;
  for (i = 0; i < dg[u]; i++) {
    v = LG[u][i];
    if (!seen[v]) {
      dfs(v, u);
      nf++;
      low[u] = min(low[u], low[v]);
      if (low[v] > d[u]) resp++;
    } else if (v != p) low[u] = min(low[u], d[v]);
  }}

int main(void) {
  int c, p, i, u, v;
  while (scanf("%d %d", &c, &p) != EOF) {
    memset(dg, 0, sizeof(dg));
    memset(seen, 0, sizeof(seen));
    for (i = 0; i < p; i++) {
      scanf("%d %d", &u, &v); u--; v--;
      LG[u][dg[u]++] = v;
      LG[v][dg[v]++] = u;
    }
    resp = tempo = 0; dfs(0, 0);
    printf("%d\n", resp);
  }
  return 0;
}
