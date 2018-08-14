#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
  int n, m, k, i, rr, rc, c1r, c1c, c2r, c2c, ans;
  scanf("%d %d %d", &n, &m, &k);
  while (k--) {
    scanf("%d %d", &rr, &rc); rr--; rc--;
    scanf("%d %d", &c1r, &c1c); c1r--; c1c--;
    scanf("%d %d", &c2r, &c2c); c2r--; c2c--;
    for (ans = i = 0; !ans && i < n; i++) {
      ans |= (dist(rr, rc, i, 0) < dist(c1r, c1c, i, 0) &&
              dist(rr, rc, i, 0) < dist(c2r, c2c, i, 0));
      ans |= (dist(rr, rc, i, m - 1) < dist(c1r, c1c, i, m - 1) &&
              dist(rr, rc, i, m - 1) < dist(c2r, c2c, i, m - 1));
    }
    for (i = 0; !ans && i < m; i++) {
      ans |= (dist(rr, rc, 0, i) < dist(c1r, c1c, 0, i) &&
              dist(rr, rc, 0, i) < dist(c2r, c2c, 0, i));
      ans |= (dist(rr, rc, n - 1, i) < dist(c1r, c1c, n - 1, i) &&
              dist(rr, rc, n - 1, i) < dist(c2r, c2c, n - 1, i));
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
  return 0;
}
