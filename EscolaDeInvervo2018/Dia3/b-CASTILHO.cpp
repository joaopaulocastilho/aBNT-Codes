#include <bits/stdc++.h>

using namespace std;

#define EPS 10e-9

const int MAXV = 12;

int main(void) {
  int n, total, v[MAXV], i, maior, flag = 2;
  scanf("%d", &n);
  for (total = i = 0; i < n; i++) {
    scanf("%d", &v[i]); total += v[i];
  }
  sort(v, v + n);
  maior = v[n - 1];
  if (EPS >= (0.45 * total) - maior) { flag = 1; }
  else if (maior >= 0.4 * total) {
    for (flag = 1, i = 0; i < n - 1; i++)
      if (maior - v[i] - 0.1 * total < EPS) flag = 2;
  }
  printf("%d\n", flag);
  return 0;
}
