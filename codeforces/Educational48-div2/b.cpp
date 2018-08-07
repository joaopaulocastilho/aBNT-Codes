#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;

int comeca[MAXV];

void computa(int l, int r, char s[], char t[]) {
  int i, j, flag = 1;
  for (j = 0, i = l; i < r; i++, j++) flag &= (s[i] == t[j]);
  comeca[l] = flag;
}

int main(void) {
  int n, m, q, i, l, r, ts, tt, ans;
  char s[MAXV], t[MAXV];
  memset(comeca, 0, sizeof(comeca));
  scanf("%d %d %d", &n, &m, &q);
  scanf(" %s %s", s, t); ts = strlen(s); tt = strlen(t);
  for (i = 0; i <= ts - tt; i++) computa(i, i + tt, s, t);
  while (q--) {
    scanf("%d %d", &l, &r); l--; r--;
    for (ans = 0, i = l; i <= (r - tt) + 1; i++) ans += comeca[i];
    printf("%d\n", ans);
  }
  return 0;
}
