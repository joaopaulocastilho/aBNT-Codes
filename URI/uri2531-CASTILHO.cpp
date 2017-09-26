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
  if(l == r) { st[p].maior = st[p].menor = l; return; }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  p1 = st[left(p)].menor; p2 = st[right(p)].menor;
  st[p].menor = a[p1] <= a[p2] ? p1 : p2;
  p1 = st[left(p)].maior; p2 = st[right(p)].maior;
  st[p].maior = a[p1] >= a[p2] ? p1 : p2;
}

int rmq(int p, int l, int r, int i, int j, int control) {
  int p1, p2;
  if(i > r || j < l) return -1;
  if(l >= i && r <= j) {
    if (control) return st[p].maior;
    return st[p].menor;
  }
  p1 = rmq(left(p), l, (l+r)/2, i, j, control);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j, control);
  if(p1 == -1) return p2;
  if(p2 == -1) return p1;
  if (control) return (a[p1] >= a[p2]) ? p1 : p2;
  return (a[p1] <= a[p2]) ? p1 : p2;
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
  int i, q, op, j, r1, r2;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    build(1, 0, n - 1);
    scanf("%d", &q);
    while (q--) {
      scanf("%d %d %d", &op, &i, &j); i--;
      if (op == 1) { a[i] = j; update(1, 0, n - 1, i); }
      else {
        j--;
        r1 = a[rmq(1, 0, n - 1, i, j, 1)];
        r2 = a[rmq(1, 0, n - 1, i, j, 0)];
        printf("%d\n", abs(r1 - r2));
      }}}
  return 0;
}
