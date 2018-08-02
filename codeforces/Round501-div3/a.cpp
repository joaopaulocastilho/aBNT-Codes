#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int main(void) {
  int n, m, ans, i, l, r, first = 1, j, seg[MAXV];
  scanf("%d %d", &n, &m);
  memset(seg, 0, sizeof(seg));
  for (i = 0; i < n; i++) {
    scanf("%d %d", &l, &r);
    for (j = l; j <= r; j++) seg[j] = 1;
  }
  for (ans = 0, i = 1; i <= m; i++) if (!seg[i]) ans++;
  printf("%d\n", ans);
  for (ans = 0, i = 1; i <= m; i++)
    if (!seg[i]) {
      if (first) first = 0;
      else printf(" ");
      printf("%d", i);
    }
  printf("\n");
  return 0;
}
