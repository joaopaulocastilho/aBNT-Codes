#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX1 1123
#define MAX2 112
#define INF 1123456789

int memo[MAX2][MAX2];

int minimo(int a, int b, int c) { return min(a, min(b, c)); }

int dist_edit(char s1[], int t1, char s2[], int t2) {
  int c;
  if (t1 == 0) return t2;
  if (t2 == 0) return t1;
  if (memo[t1][t2] != -1) return memo[t1][t2];
  c = (s1[t1 - 1] != s2[t2 - 1]);
  return memo[t1][t2] = minimo(dist_edit(s1, t1 - 1, s2, t2) + 1,
                dist_edit(s1, t1, s2, t2 - 1) + 1,
                dist_edit(s1, t1 - 1, s2, t2 - 1) + c);
}

int main(void) {
  int i, a, q, tmp, atual, resp, tam1, tam2, first = 1;
  char strs[MAX1][MAX2], s2[MAX2];
  scanf("%d ", &a);
  for (i = 0; i < a; i++) scanf("%s", strs[i]);
  scanf("%d", &q);
  while (q--) {
    scanf("%s", s2); tam2 = strlen(s2);
    for (atual = INF, i = 0; i < a; i++) {
      memset(memo, -1, sizeof(memo));
      tam1 = strlen(strs[i]);
      if ((tmp = dist_edit(strs[i], tam1, s2, tam2)) < atual) {
        atual = tmp;
        resp = i;
      }
    }
    if (first) first = 0;
    else printf(" ");
    printf("%s", strs[resp]);
  }
  printf("\n");
  return 0;
}
