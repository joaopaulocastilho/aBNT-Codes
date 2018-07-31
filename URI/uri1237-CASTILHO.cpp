#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 55

int memo[MAX][MAX], tam1, tam2;
char s1[MAX], s2[MAX];

int lcs(int a, int b) {
  if (a == tam1) return 0;
  if (b == tam2) return 0;
  if (memo[a][b] != -1) return memo[a][b];
  if (s1[a] == s2[b]) return memo[a][b] = 1 + lcs(a + 1, b + 1);
  return 0;
}

int main(void) {
  int resp, i, j;
  while (fgets(s1, MAX, stdin)) {
    fgets(s2, MAX, stdin);
    s1[tam1 = strlen(s1) - 1] = '\0';
    s2[tam2 = strlen(s2) - 1] = '\0';
    memset(memo, -1, sizeof(memo));
    for (resp = i = 0; i < tam1; i++)
      for (j = 0; j < tam2; j++)
        resp = max(resp, lcs(i, j));
    printf("%d\n", resp);
  }
  return 0;
}
