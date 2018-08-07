#include <bits/stdc++.h>

using namespace std;

typedef struct { int x, y; }ponto_t;

const int MAXV = 112;

int n, xa, xb, memo[MAXV];
ponto_t pts[MAXV];

double area(ponto_t a, ponto_t b, ponto_t c) {
  int r1, r2, ret;
  r1 = a.x * b.y + a.y * c.x + b.x * c.y;
  r2 = c.x * b.y + c.y * a.x + b.x * a.y;
  ret = abs(r1 - r2);
  return (double)ret / 2.;
}

int is_inside(ponto_t a, ponto_t b) {
  ponto_t c1, c2;
  c1.x = xa, c1.y = 0; c2.x = xb; c2.y = 0;
  double area1 = ((double)a.y * (xb - xa)) / 2.;
  double area2 = area(a, b, c1), area3 = area(a, b, c2);
  return (area1 + area2 + area3 == ((double)b.y * (xb - xa)) / 2.);
}

int dp(int p) {
  int i, ret = 0;
  if (p == n) return 0;
  if (memo[p] != -1) return memo[p];
  for (i = 0; i < n; i++) {
    if (i == p) continue;
    if (is_inside(pts[p], pts[i])) ret = max(ret, dp(i));
  }
  return memo[p] = ret + 1;
}

int main(void) {
  int i, ans;
  memset(memo, -1, sizeof(memo));
  scanf("%d %d %d", &n, &xa, &xb);
  for (i = 0; i < n; i++) scanf("%d %d", &pts[i].x, &pts[i].y);
  for (ans = i = 0; i < n; i++) ans = max(ans, dp(i));
  printf("%d\n", ans);
  return 0;
}
