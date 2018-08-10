#include <bits/stdc++.h>

const int MAXV = 21234;

int main(void) {
  int t, n, k, resp, igual, flag, i;
  char c[MAXV];
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    scanf(" %s", c);
    flag = (k == 1);
    for (igual = resp = i = 1; i < n; i++) {
      if (c[i] == c[i - 1]) {
        igual++;
        if (igual == k) flag = 1;
        if (igual > k) { igual = 1; resp++; }
      } else { resp++; igual = 1; }
    }
    printf("%d\n", flag ? resp : -1);
  }
  return 0;
}
