#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;
const int INF = 112345678;

int n, m, ans[MAXV][MAXV];
char bra[MAXV][MAXV];

int valido(int i, int j) {
  if (i < 0 || i >= n) return 0;
  if (j < 0 || j >= m) return 0;
  if (bra[i][j] == '@') return 0;
  return 1;
}

void expande(int ii, int jj) {
  int i, j, cont;
  for (i = ii + 1, cont = 1; valido(i, jj); i++, cont++)
    ans[i][jj] = min(ans[i][jj], cont);
  for (i = ii - 1, cont = 1; valido(i, jj); i--, cont++)
    ans[i][jj] = min(ans[i][jj], cont);
  for (j = jj + 1, cont = 1; valido(ii, j); j++, cont++)
    ans[ii][j] = min(ans[ii][j], cont);
  for (j = jj - 1, cont = 1; valido(ii, j); j--, cont++)
    ans[ii][j] = min(ans[ii][j], cont);
}

int main(void) {
  int i, j, ans_;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", bra[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) ans[i][j] = (bra[i][j] == '@') ? 0 : INF;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (bra[i][j] != '@') continue;
      expande(i, j);
    }
  }
  for (ans_ = -1, i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      ans_ = max(ans_, ans[i][j]);
  printf("%d\n", (ans_ == INF) ? -1 : ans_);
  return 0;
}
