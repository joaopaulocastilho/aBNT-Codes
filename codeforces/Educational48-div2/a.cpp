#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n, m, i, pos, total, qtd, ans, tmp;
  scanf("%d %d", &n, &m);
  for (pos = i = 0; i < n; i++) {
    if (i) printf(" ");
    scanf("%d", &total); tmp = total;
    qtd = m - pos;
    ans = (qtd - total <= 0);
    total = max(0, total - qtd);
    ans += total / m;
    printf("%d", ans);
    pos = (pos + tmp) % m;
    //printf("pos == %d\n", pos);
  }
  printf("\n");
  return 0;
}
