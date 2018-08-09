#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef pair<ii, int>iii;

const int MAXV = 1123456;
const int MAXG = 512;
const int INF = 112345678;

int m[MAXG][MAXG], ans, r, c;
int di[] = { 1, 0, -1, 0};
int dj[] = { 0, 1, 0, -1  };

int valido(int i, int j) {
  if (i < 0 || i >= r) return 0;
  if (j < 0 || j >= c) return 0;
  return 1;
}

int bfs(int h) {
  int vis[MAXG][MAXG], alt, li, ci, i;
  memset(vis, 0, sizeof(vis));
  queue<iii>q;
  if (m[0][0] > h) q.push(iii(ii(0, 0), h));
  while (!q.empty()) {
    li = q.front().first.first; ci = q.front().first.second;
    alt = q.front().second;
    q.pop();
    if (vis[li][ci]) continue;
    vis[li][ci] = 1;
    for (i = 0; i < 4; i++) {
      if (valido(li + di[i], ci + dj[i]) &&
	  m[li + di[i]][ci + dj[i]] > alt + 1)
	q.push(iii(ii(li + di[i], ci + dj[i]), alt + 1));
    }
  }
  return vis[r - 1][c - 1];
}

void bbin(int l, int r) {
  if (r < l) return;
  int m = (l + r) / 2;
  if (bfs(m)) { ans = max(ans, m); bbin(m + 1, r); }
  else bbin(l, m - 1);
}

int main(void) {
  int i, j;
  ans = -INF;
  scanf("%d %d", &r, &c);
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++) scanf("%d", &m[i][j]);
  bbin(0, MAXV);
  printf("%d\n", (ans == -INF) ? -1 : ans);
  return 0;
}
