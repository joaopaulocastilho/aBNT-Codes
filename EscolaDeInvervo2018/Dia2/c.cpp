#include <bits/stdc++.h>

using namespace std;

const int MAXV = 21234;

int LG[MAXV][MAXV], dg[MAXV];

int dfs(int u) {
  vis[u] = 1;
  for (i = 0; i < dg[u]; i++) {
    v = LG[u][i];
    if (!vis[v]) {
      
    }
  }
}

int main(void) {
  int t, caso;
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    printf("Case #%d: ", caso);
    scanf("%d", &n);
    memset(dg, 0, sizeof(dg));
    for (i = 0; i < n - 1; i++) {
      scanf("%d %d", &u, &v); u--; v--;
      LG[u][dg[u]++] = v;
      LG[v][dg[v]++] = u;
    }
    for (i = 0; i < n; i++) {
      memset(vis, 0, sizeof(vis));
      dfs(i);
    }
    for (resp = i = 0; i < n; i++) resp = max(resps[i], resp);
    printf("%d\n", resp);
  }
  return 0;
}
