#include <bits/stdc++.h>

using namespace std;

#define DEBUG 1
#define debugf if (DEBUG) printf

typedef long long ll;

const int MAXV =  1123456;
const int P = 1000000007;

int PI[MAXV], pi;

void crivo(int n) {
  int i, j, primo, raiz;
  PI[0] = 2; pi = 1;
  for (i = 3; i <= n; i++) {
    primo = 1; raiz = sqrt(i);
    for (j = 0; primo && j < pi && PI[j] <= raiz; j++)
      if (i % PI[j] == 0) primo = 0;
    if (primo) PI[pi++] = i;
  }
}

int fatora(int n) {
  int i;
  for (i = 0; i < pi; i++)
    if (n % PI[i] == 0) return PI[i];
  return 0;
}

ll euclides(ll a, ll b, ll &x, ll &y) {
  if (b == 0) { x = 1; y = 0; return a; }
  ll g = euclides(b, a % b, y, x);
  y -= a / b * x;
  return g;
}

ll invMul(int a, int m) {
  ll x, y;
  ll tmp = euclides(a, m, x, y);
  return (x + m) % m;
}

ll expbin(ll a, ll b, ll m) {
  if (b == 0) return 1;
  if (b & 1) return a * expbin(a, b - 1, m) % m;
  ll y = expbin(a, b >> 1, m);
  return (y * y) % m;
}

int main(void) {
  int n, e, c, p1, p2, tot;
  ll d;
  scanf("%d %d %d", &n, &e, &c);
  crivo(sqrt(n));
  p1 = fatora(n); p2 = n / p1;
  debugf("%d %d\n", p1, p2);
  tot = (p1 - 1) * (p2 - 1);
  debugf("Tot == %d\n", tot);
  d = invMul(e, tot);
  debugf("D == %lld\n", d);
  printf("%lld\n", expbin(c, d, n));
  return 0;
}
