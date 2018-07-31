#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123456;

int ataca[MAXV], atacado[MAXV];

int main(void) {
  int t, n, m, a, b, i;
  scanf("%d", &t);
  while (t--) {
    memset(ataca, 0, sizeof(ataca));
    memset(atacado, 0, sizeof(atacado));
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
      scanf("%d %d", &a, &b);
      ataca[a]++; atacado[b] = 1;
    }
    for (i = n; i; i--) {
      if (!atacado[i] && ataca[i] == n - i) {
        printf("2 %d\n", i);
        break;
      }
    }
    if (i == 0) printf("1\n");
  }
  return 0;
}
