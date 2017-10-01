#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 112345
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

typedef struct { int valor, id; }mesada_t;

int n, me[MAX], lazy[4 * MAX];
mesada_t st[4 * MAX];

void build(int p, int l, int r) {
  int meio = (l + r) / 2;
  mesada_t p1, p2;
  if (l == r) { st[p].valor = me[l]; st[p].id = l; return; }
  build(left(p), l, meio);
  build(right(p), meio + 1, r);
  p1 = st[left(p)]; p2 = st[right(p)];
  st[p].valor = max(p1.valor, p2.valor);
  st[p].id = (p1.valor >= p2.valor) ? p1.id : p2.id;
}

void range_update(int p, int l, int r, int i, int j, int val) {
  int meio = (l + r) / 2;
  mesada_t p1, p2;
  if (lazy[p]) {
    st[p].valor += lazy[p];
    if (l != r) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if (i > r || j < l) return;
  if (i <= l && j >= r) {
    st[p].valor += val;
    if (l != r) {
      lazy[left(p)] += val;
      lazy[right(p)] += val;
    }
    return;
  }
  range_update(left(p), l, meio, i, j, val);
  range_update(right(p), meio + 1, r, i, j, val);
  p1 = st[left(p)]; p2 = st[right(p)];
  st[p].valor = max(p1.valor, p2.valor);
  st[p].id = (p1.valor >= p2.valor) ? p1.id : p2.id;
}

mesada_t rmq(int p, int l, int r, int i, int j) {
  int meio = (l + r) / 2;
  mesada_t ret, p1, p2;
  if (i > r || j < l) { ret.id = -1; return ret; }
  if (lazy[p]) {
    st[p].valor += lazy[p];
    if (l != r) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if (l >= i && r <= j) return st[p];
  p1 = rmq(left(p), l, meio, i, j);
  p2 = rmq(right(p), meio + 1, r, i, j);
  if (p1.id == -1) return p2;
  if (p2.id == -1) return p1;
  if (p1.valor >= p2.valor) return p1;
  return p2;
}

int main(void) {
  int q, i, j, v; char c;
  mesada_t resp;
  while (scanf("%d %d", &n, &q) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &me[i]);
    memset(lazy, 0, sizeof(lazy)); build(1, 0, n - 1);
    while (q--) {
      scanf(" %c", &c);
      if (c == 'C') {
        scanf("%d %d", &i, &j); i--; j--;
        resp = rmq(1, 0, n - 1, i, j);
        printf("%d\n", resp.id + 1);
      } else {
        scanf("%d %d %d", &i, &j, &v); i--; j--;
        range_update(1, 0, n - 1, i, j, v);
      }}}
  return 0;
}
