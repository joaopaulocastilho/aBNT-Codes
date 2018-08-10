#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

int main(void) {
  int n, q[MAXV], nl[MAXV], i, j, ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &q[i]);
  for (i = 0; i < n; i++) scanf("%d", &nl[i]);
  sort(q, q + n);
  sort(nl, nl + n);
  for (ans = i = j = 0; i < n && j < n; ) {
    if (q[i] < nl[j]) { ans++; i++; j++; continue; }
    j++;
  }
  printf("%d\n", ans);
  return 0;
}
