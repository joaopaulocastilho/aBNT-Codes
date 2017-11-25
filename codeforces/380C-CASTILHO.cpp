#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 1123456
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

typedef struct { int ac, a, f; }chain_t;

chain_t st[4 * MAX];
char s[MAX];

void build(int p, int l, int r) {
  int meio = (l + r) / 2, desconta;
  chain_t c1, c2, new_c;
  if (l == r) {
    st[p].ac = 0;
    st[p].a = (s[l] == '(');
    st[p].f = (s[l] == ')');
    return;
  }
  build(left(p), l, meio);
  build(right(p), meio + 1, r);
  c1 = st[left(p)]; c2 = st[right(p)];
  desconta = min(c1.a, c2.f);
  new_c.ac = c1.ac + c2.ac + desconta;
  new_c.a = c1.a + c2.a - desconta;
  new_c.f = c1.f + c2.f - desconta;
  st[p] = new_c;
}

chain_t rmq(int p, int l, int r, int i, int j) {
  int meio = (l + r) / 2, desconta;
  chain_t ret, p1, p2;
  if (i > r || j < l) { ret.ac = -1; return ret; }
  if (l >= i && r <= j) return st[p];
  p1 = rmq(left(p), l, meio, i, j);
  p2 = rmq(right(p), meio + 1, r, i, j);
  if (p1.ac == -1) return p2;
  if (p2.ac == -1) return p1;

  desconta = min(p1.a, p2.f);
  ret.ac = p1.ac + p2.ac + desconta;
  ret.a = p1.a + p2.a - desconta;
  ret.f = p1.f + p2.f - desconta;
  return ret;
}

int main(void) {
  int n, m, i, j;
  chain_t resp;
  scanf("%s", s); n = strlen(s);
  build(1, 0, n - 1);
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d", &i, &j); i--; j--;
    resp = rmq(1, 0, n - 1, i, j);
    printf("%d\n", resp.ac * 2);
  }
  return 0;
}
