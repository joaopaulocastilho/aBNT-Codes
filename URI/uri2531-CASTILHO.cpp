#include<stdio.h>
#include<stdlib.h>

#define MAX 112345
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

typedef struct { int menor, maior; }seg_t;

int n, a[MAX];
seg_t st[4 * MAX];

void build(int p, int l, int r) {
  int p1, p2;
  if (l == r) { st[p].maior = st[p].menor = l; return; }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  p1 = st[left(p)].menor; p2 = st[right(p)].menor;
  st[p].menor = a[p1] <= a[p2] ? p1 : p2;
  p1 = st[left(p)].maior; p2 = st[right(p)].maior;
  st[p].maior = a[p1] >= a[p2] ? p1 : p2;
}

seg_t rmq(int p, int l, int r, int i, int j) {
  seg_t p1, p2, ret;
  if (i > r || j < l) { ret.menor = -1; return ret; }
  if (l >= i && r <= j) return st[p];
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);
  if (p1.menor == -1) return p2;
  if (p2.menor == -1) return p1;
  ret.maior = (a[p1.maior] >= a[p2.maior]) ? p1.maior : p2.maior;
  ret.menor = (a[p1.menor] <= a[p2.menor]) ? p1.menor : p2.menor;
  return ret;
}

void update(int p, int l, int r, int i) {
  int p1, p2;
  if (i > r || i < l) return;
  if (l == r) return;
  update(left(p), l, (l+r)/2, i);
  update(right(p), (l+r)/2 + 1, r, i);
  p1 = st[left(p)].menor; p2 = st[right(p)].menor;
  st[p].menor = a[p1] <= a[p2] ? p1 : p2;
  p1 = st[left(p)].maior; p2 = st[right(p)].maior;
  st[p].maior = a[p1] >= a[p2] ? p1 : p2;
}

int main(void) {
  int i, q, op, j;
  seg_t r;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    build(1, 0, n - 1);
    scanf("%d", &q);
    while (q--) {
      scanf("%d %d %d", &op, &i, &j); i--;
      if (op == 1) { a[i] = j; update(1, 0, n - 1, i); }
      else {
        j--;
        r = rmq(1, 0, n - 1, i, j);
        printf("%d\n", abs(a[r.maior] - a[r.menor]));
      }}}
  return 0;
}
