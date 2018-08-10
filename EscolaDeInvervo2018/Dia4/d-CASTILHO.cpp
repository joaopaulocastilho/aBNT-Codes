#include <bits/stdc++.h>

using namespace std;

const int MAXV = 11;

int main(void) {
  int t, n, i, j, ans;
  char s[MAXV];
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s); n = strlen(s);
    for (ans = 1, i = 0, j = n - 1; ans && i <= j; i++, j--) {
      ans &= (s[i] == s[j]);
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
  return 0;
}
