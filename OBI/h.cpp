#include <bits/stdc++.h>

using namespace std;

const int MAXV = 212345;

int ft[MAXV];

int query(int x) {
  int s;
  for (s = 0; x > 0; x -= (x & -x)) s += ft[x];
  return s;
}

void update(int x, int v) { //adicionar o valor v em x
  for ( ; x < MAXV; x += (x & -x)) ft[x] += v;
}

int main(void) {
  int n, m, op, a, b, c, d, x, y;
  scanf("%d %d\n", &n, &m);
  memset(ft, 0, sizeof(ft));
  while (m--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %d", &x, &y);
      update(x, y);
    } else {
      scanf("%d %d %d %d", &a, &b, &c, &d);
      if (a > c) { swap(a, c); swap(b, d); }
      if (b < c)
        printf("%d\n", (query(b) - query(a - 1)) + (query(d) - query(c - 1)));
      else {
        a = min(a, c); b = max(b, d);
        printf("%d\n", query(b) - query(a - 1));
      }
    }
  }
  return 0;
}
