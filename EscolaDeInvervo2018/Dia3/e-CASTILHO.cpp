#include <bits/stdc++.h>

using namespace std;

const int MAXV = 142345;

int solve(char s[], int ini, int fim) {
  int i, ans = 0, mul = 1;
  for (i = fim; i >= ini; i--) {
    if (s[i] - '0') ans += mul;
    mul *= 2;
  }
  return ans;
}

int main(void) {
  int t = 1, i, j, ans, tmpans, pot, mul, obt[MAXV], n, num;
  char s[MAXV];
  //scanf("%d", &t);
  while (t--) {
    scanf(" %s", s); n = strlen(s);
    for (ans = 17, mul = pot = 1, i = 0; i < 17; i++) {
      memset(obt, 0, sizeof(obt));
      for (j = 0; j < n - i; j++) {
        num = solve(s, j, j + i);
        obt[num] = 1;
      }
      for (tmpans = 1, j = 0; j <= pot; j++) tmpans &= obt[j];
      if (!tmpans) { ans = i + 1; break; }
      mul *= 2;
      pot += mul;
    }
    printf("%d\n", ans);
  }
  return 0;
}
