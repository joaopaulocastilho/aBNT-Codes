#include<stdio.h>
#include<stdlib.h>

#define MAX 1123

int cmp(const void *a, const void *b) {
  return *(int*)b - *(int*)a;
}

int main(void) {
  int n, k, i, nota[MAX];
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) scanf("%d", &nota[i]);
  qsort(nota, n, sizeof(int), &cmp);
  for (i = k; i < n && nota[i - 1] == nota[i]; i++);
  printf("%d\n", i);
  return 0;
}
