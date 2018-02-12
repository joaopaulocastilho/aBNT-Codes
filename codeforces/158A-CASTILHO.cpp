#include <stdio.h>

#define MAX 112

int main(void) {
  int n, k, resp = 0, i, a[MAX];
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    if (a[i] > 0 && a[i] >= a[k - 1]) resp++;
  }
  printf("%d\n", resp);
  return 0;
}
