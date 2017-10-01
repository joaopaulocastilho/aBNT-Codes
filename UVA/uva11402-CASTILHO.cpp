#include<stdio.h>
#include<string.h>
#include<utility>
using namespace std;

#define MAX 1123456
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

typedef struct { int barb, bucc; }pirate_t;

int n, land[MAX], lazy[4 * MAX];
pirate_t st[4 * MAX];

void build(int p, int l, int r) {
  int meio = (l + r) / 2;
  if (l == r) { st[p].barb = !land[l]; st[p].bucc = land[l]; return; }
  build(left(p), l, meio);
  build(right(p), meio + 1, r);
  st[p].barb = st[left(p)].barb + st[right(p)].barb;
  st[p].bucc = st[left(p)].bucc + st[right(p)].bucc;
}

void range_update(int p, int l, int r, int i, int j, int op) {
  int meio = (l + r) / 2;
  if (lazy[p]) {
    if (lazy[p] == 3) swap(st[p].barb, st[p].bucc);
    else if (lazy[p] == 1) {
      st[p].barb += st[p].bucc; st[p].bucc = 0;
    } else {
      st[p].bucc += st[p].barb; st[p].barb = 0;
    }
    if (l != r) {
      if (lazy[p] == 3) {
        if (lazy[left(p)] == 3) lazy[left(p)] = 0;
        else if (lazy[left(p)] == 2) lazy[left(p)] = 1;
        else if (lazy[left(p)] == 1) lazy[left(p)] = 2;
        else lazy[left(p)] = 3;
        if (lazy[right(p)] == 3) lazy[right(p)] = 0;
        else if (lazy[right(p)] == 2) lazy[right(p)] = 1;
        else if (lazy[right(p)] == 1) lazy[right(p)] = 2;
        else lazy[right(p)] = 3;
      } else { lazy[left(p)] = lazy[right(p)] = lazy[p]; }
    }
    lazy[p] = 0;
  }
  if (i > r || j < l) return;
  if (i <= l && j >= r) {
    if (op == 3) swap(st[p].barb, st[p].bucc);
    else if (op == 1) {
      st[p].barb += st[p].bucc; st[p].bucc = 0;
    } else {
      st[p].bucc += st[p].barb; st[p].barb = 0;
    }
    if (l != r) {
      if (op == 3) {
        if (lazy[left(p)] == 3) lazy[left(p)] = 0;
        else if (lazy[left(p)] == 2) lazy[left(p)] = 1;
        else if (lazy[left(p)] == 1) lazy[left(p)] = 2;
        else lazy[left(p)] = 3;
        if (lazy[right(p)] == 3) lazy[right(p)] = 0;
        else if (lazy[right(p)] == 2) lazy[right(p)] = 1;
        else if (lazy[right(p)] == 1) lazy[right(p)] = 2;
        else lazy[right(p)] = 3;
      } else { lazy[left(p)] = lazy[right(p)] = op; }
    }
    return;
  }
  range_update(left(p), l, meio, i, j, op);
  range_update(right(p), meio + 1, r, i, j, op);
  st[p].barb = st[left(p)].barb + st[right(p)].barb;
  st[p].bucc = st[left(p)].bucc + st[right(p)].bucc;
}

pirate_t rmq(int p, int l, int r, int i, int j) {
  int meio = (l + r) / 2;
  pirate_t p1, p2, ret;
  if (i > r || j < l) { ret.bucc = -1; return ret; }
  if (lazy[p]) {
    if (lazy[p] == 3) swap(st[p].barb, st[p].bucc);
    else if (lazy[p] == 1) {
      st[p].barb += st[p].bucc; st[p].bucc = 0;
    } else {
      st[p].bucc += st[p].barb; st[p].barb = 0;
    }
    if (l != r) {
      if (lazy[p] == 3) {
        if (lazy[left(p)] == 3) lazy[left(p)] = 0;
        else if (lazy[left(p)] == 2) lazy[left(p)] = 1;
        else if (lazy[left(p)] == 1) lazy[left(p)] = 2;
        else lazy[left(p)] = 3;
        if (lazy[right(p)] == 3) lazy[right(p)] = 0;
        else if (lazy[right(p)] == 2) lazy[right(p)] = 1;
        else if (lazy[right(p)] == 1) lazy[right(p)] = 2;
        else lazy[right(p)] = 3;
      } else { lazy[left(p)] = lazy[right(p)] = lazy[p]; }
    }
    lazy[p] = 0;
  }
  if (l >= i && r <= j) return st[p];
  p1 = rmq(left(p), l, meio, i, j);
  p2 = rmq(right(p), meio + 1, r, i, j);
  if (p1.bucc == -1) return p2;
  if (p2.bucc == -1) return p1;
  ret.barb = p1.barb + p2.barb;
  ret.bucc = p1.bucc + p2.bucc;
  return ret;
}

int main(void) {
  int tcasos, caso, m, t, i, j, tmpsize, query, a, b, q;
  char tmp[51], c; pirate_t resp;
  scanf("%d", &tcasos);
  for (caso = 1; caso <= tcasos; caso++) {
    n = 0;
    scanf("%d", &m);
    while (m--) {
      scanf("%d", &t);
      scanf(" %s", tmp);
      for (i = 0, tmpsize = (int)strlen(tmp); i < t; i++)
        for (j = 0; j < tmpsize; j++)
          land[n++] = tmp[j] - '0';
    }
    memset(lazy, 0, sizeof(lazy)); build(1, 0, n - 1);
    scanf("%d", &q); printf("Case %d:\n", caso);
    for (query = 0; q--; ) {
      scanf(" %c %d %d", &c, &a, &b);
      switch (c) {
      case 'F': range_update(1, 0, n - 1, a, b, 2); break;
      case 'E': range_update(1, 0, n - 1, a, b, 1); break;
      case 'I': range_update(1, 0, n - 1, a, b, 3); break;
      case 'S':
        resp = rmq(1, 0, n - 1, a, b); query++;
        printf("Q%d: %d\n", query, resp.bucc);
        break;
      }
    }
  }
  return 0;
}
