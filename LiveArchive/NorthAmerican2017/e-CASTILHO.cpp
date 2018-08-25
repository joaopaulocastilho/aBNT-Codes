#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back((x));

typedef pair<int, int>ii;
typedef vector<ii>vii;
typedef vector<vii>vvii;

const int MAXV = 1123;
const int MAXA = 11234;

int vis[MAXV], tem[MAXA];

void has_dfs(int u, int dest, int flag, vvii &LG) {
  int i, v, tipo, tmp;
  if (u != dest) vis[u] = 1;
  if (u == dest && flag) vis[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i].first; tipo = LG[u][i].second;
    tmp = (flag || tipo || tem[v] || tem[u]);
    if (!vis[v]) {
      if (v == dest && tmp) has_dfs(v, dest, tmp, LG);
      else if (v != dest) has_dfs(v, dest, tmp, LG);
    }
  }
}

void is_dfs(int u, int dest, vvii &LG) {
  int i, v, tipo;
  vis[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i].first; tipo = LG[u][i].second;
    if (!vis[v] && tipo == 0) is_dfs(v, dest, LG);
  }
}

int main(void) {
  int i, n, m, u, v, ind, tipo;
  char c1[MAXV], c2[MAXV], r[MAXV];
  while (scanf("%d %d", &n, &m) != EOF) {
    map<string, int>classe;
    vvii LG(n);
    memset(tem, 0, sizeof(tem));
    for (ind = i = 0; i < n; i++) {
      scanf(" %s %s %s", c1, r, c2);
      if (classe.find(c1) == classe.end()) classe[c1] = ind++;
      if (classe.find(c2) == classe.end()) classe[c2] = ind++;
      u = classe[c1]; v = classe[c2];
      tipo = strcmp(r, "is-a") ? 1 : 0; //0: is-a. 1: has-a.
      if (tipo && u == v) tem[u] = 1;
      LG[u].pb(ii(v, tipo));
    }
    for (i = 0; i < (int)classe.size(); i++) {
      memset(vis, 0, sizeof(vis));
      has_dfs(i, i, 0, LG);
      tem[i] |= vis[i];
    }
    for (i = 1; i <= m; i++) {
      scanf(" %s %s %s", c1, r, c2);
      u = classe[c1]; v = classe[c2];
      memset(vis, 0, sizeof(vis));
      if (strcmp(r, "is-a")) {
        has_dfs(u, v, 0, LG);
        if (u == v) vis[u] |= tem[u];
      }
      else {
        if (u == v) vis[v] = 1;
        else is_dfs(u, v, LG);
      }
      printf("Query %d: %s\n", i, vis[v] ? "true" : "false");
    }
  }
  return 0;
}
