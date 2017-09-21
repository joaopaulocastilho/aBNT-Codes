#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 31
#define MAXV 1123456
#define INF 1123456789

int main(void) {
  int t, n, m, ice[MAX], memo[MAXV], i, j;
  scanf("%d\n", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &ice[i]);
    for (memo[0] = 0, i = 1; i <= m; i++) memo[i] = INF;
    for (i = 0; i < n; i++)
      for (j = ice[i]; j <= m; j++)
        memo[j] = min(memo[j], memo[j - ice[i]] + 1);
    printf("%d\n", memo[m]);
  }
  return 0;
}
