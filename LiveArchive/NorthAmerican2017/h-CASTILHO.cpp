#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int n, m, vis[MAXV][MAXV];
char MA[MAXV][MAXV];
int di[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dj[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int valido(int i, int j) {
  if (i < 0 || i >= n) return 0;
  if (j < 0 || j >= m) return 0;
  return 1;
}

void dfs(int i, int j) {
  int k, ni, nj;
  vis[i][j] = 1;
  for (k = 0; k < 8; k++) {
    ni = i + di[k]; nj = j + dj[k];
    if (valido(ni, nj) && !vis[ni][nj] && MA[ni][nj] == '#') {
      dfs(ni, nj);
    }
  }
}

int main(void) {
  int i, j, ans;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) scanf(" %s", MA[i]);
    memset(vis, 0, sizeof(vis));
    for (ans = i = 0; i < n; i++)
      for (j = 0; j < m; j++)
	if (!vis[i][j] && MA[i][j] == '#') { ans++; dfs(i, j); }
    printf("%d\n", ans);
  }
  return 0;
}
