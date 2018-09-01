#include <bits/stdc++.h>

using namespace std;

const int MAXV = 2123;

int n, poema[MAXV];
vector<int>vdiv;

void divisores(int n) {
  int i;
  for (i = 2; i <= n; i++)
    if (n % i == 0) vdiv.push_back(i);
}

int elegante(int k) {
  int i, nk = n / k, rest[MAXV];
  memset(rest, 0, sizeof(rest));
  for (i = 0; i < n; i++) rest[poema[i] % k]++;
  for (i = 0; i < k; i++)
    if (rest[i] != nk) return 0;
  return 1;
}

int main(void) {
  int i, ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &poema[i]);
  divisores(n);
  for (ans = -1, i = 0; ans == -1 && i < (int)vdiv.size(); i++)
    if (elegante(vdiv[i])) ans = vdiv[i];
  printf("%d\n", ans);
  return 0;
}
