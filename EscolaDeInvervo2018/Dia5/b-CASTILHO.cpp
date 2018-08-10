#include <bits/stdc++.h>

using namespace std;

const int MAXV = 5123;

int main(void) {
  int a, b, ans, i, j, qtdb, n;
  char s[MAXV];
  while (scanf("%d %d", &a, &b) != EOF) {
    scanf(" %s", s); n = strlen(s);
    for (qtdb = i = 0; i < n; i++) qtdb += (s[i] == 'B');
    for (ans = 0, i = qtdb - 1, j = qtdb; i >= 0 && j < n; ) {
      if (s[i] == 'B') { i--; continue; }
      if (s[j] == 'W') { j++; continue; }
      if ((j - i) * (a - b) <= a) {
        ans += (j - i) * (a - b);
        s[j] = 'W';
        i--; j++;
        continue;
      }
      break;
    }
    for (i = qtdb; i < n; i++) ans += (s[i] == 'B') ? a : 0;
    printf("%d\n", ans);
  }
  return 0;
}
