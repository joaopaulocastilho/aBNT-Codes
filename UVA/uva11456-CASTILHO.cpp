#include <bits/stdc++.h>

using namespace std;

const int MAXV = 2123;
const int INF = 112345678;

typedef vector<int>vi;

int main(void) {
  int t, i, j, ans, n, vlis[MAXV], vlds[MAXV];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vi v(n);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    for (i = n - 1; i >= 0; i--) {
      vlis[i] = 1; vlds[i] = 1;
      for (j = i + 1; j < n; j++) {
	if (v[i] < v[j]) vlis[i] = max(vlis[i], vlis[j] + 1);
	if (v[i] > v[j]) vlds[i] = max(vlds[i], vlds[j] + 1);
      }
    }
    for (ans = 0, i = 0; i < n; i++)
      ans = max(ans, vlis[i] + vlds[i] - 1);
    printf("%d\n", ans);
  }
  return 0;
}
