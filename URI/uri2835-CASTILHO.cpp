#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n, i, ans;
  scanf("%d", &n);
  vector<int>v(n);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  if (v[0] > 8) { printf("N\n"); return 0; }
  for (i = 0; i < n - 1 && v[i] <= 8; i++);
  for (ans = 1; i < n; i++) ans &= (v[i] - v[i - 1] <= 8);
  printf("%c\n", ans ? 'S' : 'N');
  return 0;
}
