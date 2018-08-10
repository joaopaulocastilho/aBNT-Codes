#include <bits/stdc++.h>

using namespace std;

const int MAXV = 11234;

int main(void) {
  int n, resp, i, v[MAXV];
  while (scanf("%d", &n), n) {
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    v[0] = v[n]; v[n + 1] = v[1];
    for (resp = 0, i = 1; i <= n; i++)
      if ((v[i - 1] > v[i] && v[i + 1] > v[i]) ||
          (v[i - 1] < v[i] && v[i + 1] < v[i])) resp++;
    printf("%d\n", resp);
  }
  return 0;
}
