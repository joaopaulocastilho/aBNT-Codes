#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1123;
const int TAMP = 112;
const int INF = 112345678;

int edit_dist(char s1[], char s2[]) {
  int i, j, tam1, tam2, memo[TAMP][TAMP];
  tam1 = strlen(s1); tam2 = strlen(s2);
  for (i = 0; i <= tam1; i++) memo[0][i] = i;
  for (i = 0; i <= tam2; i++) memo[i][0] = i;
  for (i = 1; i <= tam1; i++) {
    for (j = 1; j <= tam2; j++) {
      if (s1[i - 1] == s2[j - 1]) memo[i][j] = memo[i - 1][j - 1];
      else memo[i][j] = min(memo[i - 1][j], min(memo[i][j - 1], memo[i - 1][j - 1])) + 1;
    }
  }
  return memo[tam1][tam2];
}

int main(void) {
  int n, q, i, first, de, menor, ans;
  char palavras[MAXV][TAMP], p[TAMP];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf(" %s", palavras[i]);
  scanf("%d", &q);
  for (first = 1; q--; first = 0) {
    scanf(" %s", p);
    for (menor = INF, ans = i = 0; i < n; i++)
      if ((de = edit_dist(palavras[i], p)) < menor) { ans = i; menor = de; }
    if (!first) printf(" ");
    printf("%s", palavras[ans]);
  }
  printf("\n");
  return 0;
}
