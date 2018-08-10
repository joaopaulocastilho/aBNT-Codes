#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;
typedef vector<vi>vvi;

const int MAXV = 51;
const int MAXN = 21;

int vis[MAXV], ok[MAXV];

int dfs(int u, vvi &LG, vi &ans) {
  int i, v, ret = 1;
  vis[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i];
    if (ok[v]) continue;
    if (vis[v]) return 0;
    ret &= dfs(v, LG, ans);
  }
  ans.push_back(u);
  ok[u] = 1;
  return ret;
}

int main(void) {
  int n, m, i, u, v, ans, caso = 1;
  char nomes[MAXV][MAXN], tmp_nome[MAXN];
  while (scanf("%d", &n), n) {
    vvi LG(n);
    vi v_ans;
    map<string, int>vert;
    for (i = 0; i < n; i++) {
      scanf(" %s", nomes[i]);
      vert[nomes[i]] = i;
    }
    for (i = 0; i < n; i++) {
      scanf(" %s %d", tmp_nome, &m); u = vert[tmp_nome];
      while (m--) {
        scanf(" %s", tmp_nome); v = vert[tmp_nome];
        LG[u].push_back(v);
      }
    }
    memset(vis, 0, sizeof(vis));
    memset(ok, 0, sizeof(ok));
    for (ans = 1, i = 0; ans && i < n; i++)
      if (!vis[i]) ans = dfs(i, LG, v_ans);
    printf("Teste %d\n", caso); caso++;
    if (ans) {
      for (i = 0; i < (int)v_ans.size(); i++) {
        if (i) printf(" ");
        printf("%s", nomes[v_ans[i]]);
      }
      printf("\n");
    } else printf("impossivel\n");
    printf("\n");
  }
  return 0;
}
