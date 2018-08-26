#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long>ii;

const int MAXV = 11234;

int vis[MAXV], n;
ii ans[MAXV];
vector<int>LG[MAXV];

long long pares(vector<long long> &n_vert, int k) {
  int i, j;
  long long ret = 0;
  for (i = 0; i < k; i++)
    for (j = i + 1; j < k; j++)
      ret += n_vert[i] * n_vert[j];
  return ret;
}

int dfs(int u, int q) {
  int v, i, tmp = 0, total = 0;
  vector<long long>vert;
  vis[u] = 1;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i];
    if (!vis[v]) {
      tmp = dfs(v, q + 1);
      total += tmp;
      vert.push_back(tmp);
    }
  }
  vert.push_back(n - total);
  ans[u].first = pares(vert, vert.size());
  if ((int)vert.size() < 2) ans[u].second = 0;
  else {
    sort(vert.begin(), vert.end());
    vert[vert.size() - 2] += vert[vert.size() - 1];
    ans[u].second = pares(vert, vert.size() - 1);
  }
  return total + 1;
}

int main(void) {
  int i, u, v, ind;
  long long maior;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < MAXV; i++) LG[i].clear();
    for (i = 0; i < n; i++) {
      scanf("%d %d", &u, &v);
      LG[u].push_back(v);
      LG[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    for (i = 0; (int)LG[i].size() > 1; i++);
    dfs(i, 0);
    for (ind = 0, maior = i = 0; i < n + 1; i++)
      if (ans[i].first > maior) {
        maior = ans[i].first;
        ind = i;
      }
    printf("%lld %lld\n", ans[ind].first, ans[ind].second);
  }
  return 0;
}
