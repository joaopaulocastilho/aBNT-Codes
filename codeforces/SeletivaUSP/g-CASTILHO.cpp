#include <bits/stdc++.h>

using namespace std;

#define left(x) (x) << 1
#define right(x) ((x) << 1) + 1
#define DEBUG 0
#define debugf if (DEBUG) printf

typedef long long ll;
typedef pair<ll, ll>pll;

const int MAXV = 2123456;
const int CORR = 1000000000;
const ll INF = 11234567890;

pll sold[MAXV], st[4 * MAXV];

ll maior(ll a, ll b) { return (a > b) ? a : b; }
ll menor(ll a, ll b) { return (a < b) ? a : b; }

int valido(pll a) {
  if (a.first == INF || a.second == -INF) return 0;
  return 1;
}

void build(int p, int l, int r) {
  int meio = (l + r) / 2;
  pll p1, p2;
  if (l == r) { st[p] = sold[l]; return; }
  build(left(p), l, meio);
  build(right(p), meio + 1, r);
  p1 = st[left(p)]; p2 = st[right(p)];
  st[p] = pll(maior(p1.first, p2.first), menor(p1.second, p2.second));
  debugf("-->%lld, %lld\n", st[p].first, st[p].second);
}

pll consulta(int p, int l, int r, int i, int j) {
  int meio = (l + r) / 2;
  pll p1, p2;
  if (i > r || j < l) return pll(INF, -INF);
  if (l >= i && r <= j) return st[p];
  p1 = consulta(left(p), l, meio, i, j);
  p2 = consulta(right(p), meio + 1, r, i, j);
  if (!valido(p1)) return p2;
  if (!valido(p2)) return p1;
  return pll(maior(p1.first, p2.first), menor(p1.second, p2.second));
}

void update(int p, int l, int r, int i) {
  int meio = (l + r) / 2;
  pll p1, p2;
  if (i > r || i < l) return;
  if (l == r) { st[p] = sold[i]; return; }
  update(left(p), l, meio, i);
  update(right(p), meio + 1, r, i);
  p1 = st[left(p)]; p2 = st[right(p)];
  st[p] = pll(maior(p1.first, p2.first), menor(p1.second, p2.second));
}

int main(void) {
  int n, q, i, a, b;
  char c;
  ll ini, fim;
  pll ans;
  scanf("%d %d", &n, &q);
  for (i = 0; i < n; i++) {
    scanf("%lld %lld", &ini, &fim);
    sold[i] = pll(ini + CORR, fim + CORR);
  }
  build(1, 0, n - 1);
  while (q--) {
    scanf(" %c", &c);
    if (c == '?') {
      scanf("%d %d", &a, &b); a--; b--;
      ans = consulta(1, 0, n - 1, a, b);
      debugf("%lld %lld\n", ans.first, ans.second);
      printf("%lld\n", maior(0, (ans.second - ans.first) + 1));
    } else {
      scanf("%d %lld %lld", &i, &ini, &fim); i--;
      sold[i] = pll(ini + CORR, fim + CORR);
      update(1, 0, n - 1, i);
    }
  }
  return 0;
}
