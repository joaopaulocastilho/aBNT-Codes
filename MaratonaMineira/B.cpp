#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 5123
#define INF 112345678

typedef long long ll;

int LG[MAX][MAX], dg[MAX], venda[MAX], acum[MAX], seen[MAX], d, n;
int memo[MAX][MAX];

int dfs(int u, int t, int l) {
  int i, v;
  seen[u] = 1;
  if (u == t) return 1;
  for (i = 0; i < dg[u]; i++) {
    v = LG[u][i];
    if (!seen[v] && dfs(v, t, l)) { acum[v] += l; return 1; }
  }
  return 0;
}

ll pd(int i, int val) {
  if (i == n) return 0;
  if (memo[i][val] != -1) return memo[i][val];
  if (val + venda[i] > d) return memo[i][val] = pd(i + 1, val);
  return memo[i][val] = max(pd(i + 1, val),
                            pd(i + 1, val + venda[i]) + acum[i]);
}

int main(void) {
  int i, u, v, m, ci, vi, q, x, y, l;
  scanf("%d %d", &n, &d);
  for (i = 0; i < n; i++) venda[i] = INF;
  memset(dg, 0, sizeof(dg));
  memset(acum, 0, sizeof(acum));
  for (i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v); u--; v--;
    LG[u][dg[u]++] = v;
    LG[v][dg[v]++] = u;
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &ci, &vi); ci--;
    venda[ci] = vi;
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    memset(seen, 0, sizeof(seen));
    scanf("%d %d %d", &x, &y, &l); x--; y--;
    dfs(x, y, l); acum[x] += l;
  }
  memset(memo, -1, sizeof(memo));
  printf("%lld\n", pd(0, 0));
  return 0;
}
