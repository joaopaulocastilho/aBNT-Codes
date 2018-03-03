#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 1123456

typedef struct { int s, t; } bh;

int main(void) {
  int casos, a, b, c, pa, pos[MAX], dado, a1, a2, i, win;
  bh tab[112];
  scanf("%d", &casos);
  while (casos--) {
    memset(tab, 0, sizeof(tab));
    scanf("%d %d %d", &a, &b, &c);
    for (i = 0; i < a; i++) pos[i] = 1;
    for (i = 0; i < b; i++) {
      scanf("%d %d", &a1, &a2);
      tab[a1].s = a2; tab[a2].t = a1;
    }
    for (win = i = 0; i < c; i++) {
      scanf("%d", &dado);
      pa = (i % a);
      if (!win) {
        pos[pa] += dado;
        if (tab[pos[pa]].s) pos[pa] = tab[pos[pa]].s;
        if (pos[pa] >= 100) win = 1;
      }
    }
    for (i = 0; i < a; i++)
      printf("Position of player %d is %d.\n", i + 1, min(100, pos[i]));
  }
  return 0;
}
