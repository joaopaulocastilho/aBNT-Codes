#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

typedef pair<int, int>ii;
typedef vector<ii>vi;
typedef vector<vi>vvi;

typedef struct { int c, p; }node_t;

int amg[MAXV], vis[MAXV], ans;

node_t dfs(vvi &LG, int u, int peso) {
  int i, v, p_aux, maior = 0;
  node_t tmp, ret;
  vis[u] = 1;
  ret.p = amg[u];
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i].first; p_aux = LG[u][i].second;
    if (vis[v]) continue;
    tmp = dfs(LG, v, p_aux);
    ret.p |= tmp.p;
    if (tmp.c > maior) { ans += maior; maior = tmp.c; }
    else ans += tmp.c;
  }
  ret.c = ret.p ? peso + maior : 0;
  return ret;
}

int main(void) {
  int n, f, i, a, b, w, tmp;
  while (scanf("%d %d", &n, &f) != EOF) {
    vvi LG(n); ans = 0;
    memset(amg, 0, sizeof(amg));
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n - 1; i++) {
      scanf("%d %d %d", &a, &b, &w); a--; b--;
      LG[a].push_back(ii(b, w));
      LG[b].push_back(ii(a, w));
    }
    for (i = 0; i < f; i++) { scanf("%d", &tmp); amg[tmp - 1] = 1; }
    dfs(LG, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
