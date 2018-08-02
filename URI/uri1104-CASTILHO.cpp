#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

int main(void) {
  int a, b, ta, tb, va[MAXV], vb[MAXV], i, ca, cb;
  while (scanf("%d %d", &a, &b), a) {
    memset(va, 0, sizeof(va));
    memset(vb, 0, sizeof(vb));
    for (i = 0; i < a; i++) {
      scanf("%d", &ca); va[ca]++;
    }
    for (i = 0; i < b; i++) {
      scanf("%d", &cb); vb[cb]++;
    }
    for (ta = 0, tb = 0, i = 0; i < MAXV; i++) {
      if (va[i] == 0 && vb[i] >= 1) tb++;
      else if (va[i] >= 1 && vb[i] == 0) ta++;
    }
    printf("%d\n", min(ta, tb));
  }
  return 0;
}
