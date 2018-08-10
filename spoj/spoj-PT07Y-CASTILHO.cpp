#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;
typedef vector<vi>vvi;

const int MAXV = 11234;

int vis[MAXV];
vvi LG(MAXV);

int temCiclo(int u, int p) {
  int i, v;
  vis[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i];
    if (vis[v] && v != p) return 1;
    if (!vis[v] && temCiclo(v, u)) return 1;
  }
  return 0;
}

int main(void) {
  int n, m, i, u, v, ans;
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &u, &v); u--; v--;
    LG[u].push_back(v);
    LG[v].push_back(u);
  }
  memset(vis, 0, sizeof(vis));
  for (ans = temCiclo(0, 0), i = 0; !ans && i < n; i++)
    ans |= !vis[i];
  printf("%s\n", ans ? "NO" : "YES");
  return 0;
}
