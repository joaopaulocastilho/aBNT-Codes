#include <bits/stdc++.h>

using namespace std;

const int MAXV = 212345;

int ft[MAXV];

int query(int x) {
  int s;
  for (s = 0; x > 0; x -= (x & -x)) s += ft[x];
  return s;
}

void update(int x, int v) {
  for ( ; x <= MAXV; x += (x & -x)) ft[x] += v;
}

int main(void) {
  int n, i, p[MAXV], a, b, caso = 1;
  char op, lixo;
  while (scanf("%d", &n), n) {
    memset(ft, 0, sizeof(ft));
    if (caso > 1) printf("\n");
    printf("Case %d:\n", caso); caso++;
    for (i = 1; i <= n; i++) {
      scanf("%d", &p[i]);
      update(i, p[i]);
    }
    while (scanf(" %c", &op), op != 'E') {
      scanf("%d %d", &a, &b);
      //printf("%c %d %d\n", op, a, b);
      if (op == 'S') {
        update(a, -p[a]);
        update(a, b);
        p[a] = b;
      } else printf("%d\n", query(b) - query(a - 1));
    }
    scanf("%c%c", &op, &lixo);
  }
  return 0;
}
