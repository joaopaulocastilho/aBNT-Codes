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

matrix matrixExp(matrix a, ll n) {
  if (n == 0) return id((int)a.size());
  matrix c = matrixExp(a, n / 2);
  c = c * c;
  if (n & 1) c = c * a;
  return c;
}

long long expbin(long long a, long long b, long long m) {
  long long y;
  if (b == 0) return 1;
  if (b & 1) return a * expbin(a, b - 1, m) % m;
  y = expbin(a, b >> 1, m);
  return y * y % m;
}

int main(void) {
  ll n, tmp;
  matrix p, mul, ans;
  mul.resize(2);
  mul[0].resize(1); mul[1].resize(1);
  mul[0][0] = 30; mul[1][0] = 24;
  p.resize(2); p[0].resize(2); p[1].resize(2);
  p[0][0] = 30; p[0][1] = 25; p[1][0] = 16; p[1][1] = 20;
  scanf("%lld", &n);
  if (n == 1) { printf("12\n"); return 0; }
  if (n == 2) { printf("54\n"); return 0; }
  p = matrixExp(p, n - 2);
  ans = p * mul;
  tmp = expbin(10, n - 2, P);
  tmp = expbin(tmp, P-2, P);
  //printf("%lld\n", tmp);
  printf("%lld\n", ((ans[0][0] + ans[1][0]) * tmp) % P);
  return 0;
}
