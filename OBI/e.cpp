#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;
const int MAXN = 312;

typedef vector<int>vi;

int vis[MAXN];
vi LG[MAXN];

void dfs(int u) {
  int i;
  vis[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++)
    if (!vis[LG[u][i]]) dfs(LG[u][i]);
}

int main(void) {
  int n, m, i, u, v, id, ans;
  char nome1[MAXV], rel[MAXV], nome2[MAXV];
  map<string, int>nomes;
  scanf("%d %d", &n, &m);
  for (id = 0, i = 0; i < m; i++) {
    scanf("%s %s %s", nome1, rel, nome2);
    if (nomes.find(nome1) == nomes.end()) nomes[nome1] = id++;
    if (nomes.find(nome2) == nomes.end()) nomes[nome2] = id++;
    u = nomes[nome1]; v = nomes[nome2];
    LG[u].push_back(v);
    LG[v].push_back(u);
  }
  memset(vis, 0, sizeof(vis));
  for (ans = i = 0; i < n; i++)
    if (!vis[i]) { ans++; dfs(i); }
  printf("%d\n", ans);
  return 0;
}
