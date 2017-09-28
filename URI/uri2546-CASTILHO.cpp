#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 112345
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

int n, a[MAX], st[4 * MAX], lazy[4 * MAX];

void build(int p, int l, int r) {
  if(l == r) { st[p] = a[l]; return; }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  st[p] = max(st[left(p)], st[right(p)]);
}

int rmq(int p, int l, int r, int i, int j) {
  int p1, p2;
  if(i > r || j < l) return -1;
  if (lazy[p]) {
    st[p] += lazy[p];
    if (l != r) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if(l >= i && r <= j) return st[p];
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);
  if(p1 == -1) return p2;
  if(p2 == -1) return p1;
  return max(p1, p2);
}

void updateRange(int p, int l, int r, int i, int j, int val) {
  int meio;
  if (lazy[p]) {
    st[p] += lazy[p];
    if (l != r) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if (i > r || j < l) return;
  if (i <= l  && j >= r) {
    st[p] += val;
    if (l != r) {
      lazy[left(p)] += val;
      lazy[right(p)] += val;
    }
    return;
  }
  meio = (l + r) / 2;
  updateRange(left(p), l, meio, i, j, val);
  updateRange(right(p), meio + 1, r, i, j, val);
  st[p] = max(st[left(p)], st[right(p)]);
}

int main(void) {
  int q, i, nv, j;
  char c;
  while (scanf("%d %d", &n, &q) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    memset(lazy, 0, sizeof(lazy)); build(1, 0, n - 1);
    while (q--) {
      scanf(" %c", &c);
      switch (c) {
      case 'A':
        scanf("%d %d %d", &i, &j, &nv); i--; j--;
        updateRange(1, 0, n - 1, i, j, nv);
        break;
      case 'C':
        scanf("%d %d", &i, &j); i--; j--;
        printf("%d\n", rmq(1, 0, n - 1, i, j));
        break;
      }}}
  return 0;
}
