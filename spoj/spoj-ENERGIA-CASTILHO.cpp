#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

typedef vector<int>vi;
typedef vector<vi>vvi;

int vis[MAXV];

void dfs(int u, vvi&LG) {
  int i, v;
  vis[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i];
    if (!vis[v]) dfs(v, LG);
  }
}

int main(void) {
  int i, e, l, u, v, cont, caso = 1;
  while (scanf("%d %d", &e, &l), e) {
    vvi LG(e);
    for (i = 0; i < l; i++) {
      scanf("%d %d", &u, &v); u--; v--;
      LG[u].push_back(v);
      LG[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    for (cont = i = 0; cont < 2 && i < e; i++)
      if (!vis[i]) { cont++; dfs(i, LG); }
    printf("Teste %d\n", caso); caso++;
    printf("%s\n\n", (cont == 1) ? "normal" : "falha");
  }
  return 0;
}
