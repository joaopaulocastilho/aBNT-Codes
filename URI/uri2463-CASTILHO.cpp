#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 51234
#define INF 112345678

int sala[MAX], memo[MAX];

int pd(int i) {
  if (i < 0) return -INF;
  if (memo[i] != -INF) return memo[i];
  return memo[i] = max(sala[i], sala[i] + pd(i - 1));
}

int main(void) {
  int n, resp, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) memo[i] = -INF;
  for (i = 0; i < n; i++) scanf("%d", &sala[i]);
  for (resp = -INF, i = n - 1; i; i--) resp = max(resp, pd(i));
  printf("%d\n", resp);
  return 0;
}
