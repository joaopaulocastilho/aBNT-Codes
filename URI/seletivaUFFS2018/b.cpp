#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 5123

int memo[MAX][MAX], tam1, tam2;
char s1[MAX], s2[MAX];

int lcs(int a, int b) {
  if (a == tam1) return 0;
  if (b == tam2) return 0;
  if (memo[a][b] != -1) return memo[a][b];
  if (s1[a] == s2[b]) return memo[a][b] = 1 + lcs(a + 1, b + 1);
  return memo[a][b] = max(lcs(a + 1, b), lcs(a, b + 1));
}

int main(void) {
  scanf("%s %s", s1, s2);
  tam1 = strlen(s1);
  tam2 = strlen(s2);
  memset(memo, -1, sizeof(memo));
  printf("%d\n", lcs(0, 0));
  return 0;
}
