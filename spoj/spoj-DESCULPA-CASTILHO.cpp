#include <bits/stdc++.h>

using namespace std;

const int MAXF = 57;
const int MAXV = 1123;

typedef pair<int, int>ii;

int c, f, memo[MAXF][MAXV];
ii frase[MAXF];

int dp(int i, int t) {
  if (i == f) return 0;
  if (memo[i][t] != -1) return memo[i][t];
  if (t + frase[i].first > c) return memo[i][t] = dp(i + 1, t);
  return memo[i][t] = max(dp(i + 1, t), dp(i + 1, t + frase[i].first) + frase[i].second);
}

int main(void) {
  int i, caso = 1;
  while (scanf("%d %d", &c, &f), c) {
    printf("Teste %d\n", caso); caso++;
    for (i = 0; i < f; i++) scanf("%d %d", &frase[i].first, &frase[i].second);
    memset(memo, -1, sizeof(memo));
    printf("%d\n\n", dp(0, 0));
  }
  return 0;
}
