#include<stdio.h>
#include<string.h>

#define MAX 212345

int ft[MAX];

int rsq(int x) {
  int s = 0;
  while (x > 0) {
    s += ft[x];
    x -= (x & -x);
  }
  return s;
}

void insert(int x) {
  while (x <= MAX) {
    ft[x] += 1;
    x += (x & -x);
  }
}

int main(void) {
  int pi, m, cp, na, a, b, qtdr, resp;
  while (scanf("%d %d", &pi, &m) != EOF) {
    resp = 0; memset(ft, 0, sizeof(ft));
    while (m--) {
      scanf("%d %d", &cp, &na);
      a = (cp - pi <= 0) ? 1 : cp - pi;
      b = cp + pi;
      qtdr = rsq(b) - rsq(a - 1);
      if (qtdr <= na) { insert(cp); resp++; }
    }
    printf("%d\n", resp);
  }
  return 0;
}
