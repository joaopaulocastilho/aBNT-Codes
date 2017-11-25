#include<stdio.h>

#define MAX 1123

int main(void) {
  int n, a[MAX], i, resp = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 1; i < n - 1; i++)
    if ((a[i] < a[i - 1] && a[i] < a[i + 1]) ||
        (a[i] > a[i - 1] && a[i] > a[i + 1])) resp++;
  printf("%d\n", resp);
  return 0;
}
