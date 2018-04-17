#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 17

typedef struct { int l1, l2; }piece_t;

int n, m, resp, use[MAX];
piece_t lp, rp, vp[MAX];

void bt(int id, int line[]) {
  int i;
  if (id == n + 1 && vp[line[id - 1]].l2 == vp[line[id]].l1) { resp = 1; return; }
  if (id == n + 1) return;
  for (i = 1; i <= m; i++) {
    if (vp[line[id - 1]].l2 == vp[i].l2 && !use[i])
      swap(vp[i].l1, vp[i].l2);
    if (vp[line[id - 1]].l2 == vp[i].l1 && !use[i]) {
      use[i] = 1; line[id] = i;
      bt(id + 1, line);
      use[i] = 0;
    }
  }
}

int main(void) {
  int i, line[MAX];
  while (scanf("%d", &n), n) {
    memset(line, 0, sizeof(line));
    memset(use, 0, sizeof(use));
    scanf("%d", &m);
    scanf("%d %d", &lp.l1, &lp.l2);
    scanf("%d %d", &rp.l1, &rp.l2);
    for (resp = 0, i = 1; i <= m; i++) scanf("%d %d", &vp[i].l1, &vp[i].l2);
    vp[0] = lp; vp[i] = rp;
    line[0] = 0; line[n + 1] = i;
    bt(1, line);
    printf("%s\n", resp ? "YES" : "NO");
  }
  return 0;
}
