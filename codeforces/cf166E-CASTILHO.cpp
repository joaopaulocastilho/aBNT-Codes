#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll>vll;
typedef vector<vll>matrix;

const int P = 1000000007;

matrix operator *(matrix a, matrix b) {
  int n = (int)a.size();
  int m = (int)b.size();
  int p = (int)b[0].size();
  matrix c;
  c.resize(n);
  for (int i = 0; i < n; i++) {
    c[i].assign(p, 0);
    for (int j = 0; j < p; j++)
      for (int k = 0; k < m; k++)
        c[i][j] = c[i][j] + (((a[i][k] % P) * (b[k][j] % P)) % P) % P;
  }
  return c;
}

matrix id(int n) {
  int i, j;
  matrix ret;
  ret.resize(n);
  for (i = 0; i < n; i++) {
    ret[i].assign(n, 0);
    for (j = 0; j < n; j++)
      if (i == j) ret[i][j] = 1;
  }
  return ret;
}

matrix matrixExp(matrix a, int n) {
  if (n == 0) return id((int)a.size());
  matrix c = matrixExp(a, n / 2);
  c = c * c;
  if (n & 1) c = c * a;
  return c;
}

int main(void) {
  int n;
  matrix p, mul, ans;
  p.resize(2);
  p[0].resize(2); p[1].resize(2);
  p[0][0] = 2; p[0][1] = 1; p[1][0] = 3; p[1][1] = 0;
  mul.resize(2);
  mul[0].resize(1); mul[1].resize(1);
  mul[0][0] = 0; mul[1][0] = 1;
  scanf("%d", &n);
  p = matrixExp(p, n);
  ans = p * mul;
  printf("%lld\n", ans[1][0]);
  return 0;
}
