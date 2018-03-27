#include <stdio.h>

#define MAX 1123

int main(void) {
  int t, n, i, j, resp, v[MAX];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    for (resp = 0, i = 1; i < n; i++)
      for (j = i - 1; j >= 0; j--)
        if (v[i] >= v[j]) resp++;
    printf("%d\n", resp);
  }
  return 0;
}
