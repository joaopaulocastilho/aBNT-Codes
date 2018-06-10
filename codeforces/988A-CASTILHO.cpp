#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  int i, j, n, k, tmp, qtd, v[MAX];
  scanf("%d %d", &n, &k);
  memset(v, 0, sizeof(v));
  for (qtd = 0, i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    if (v[tmp]) continue;
    qtd++; v[tmp] = i;
  }
  printf("%s\n", (qtd < k) ? "NO" : "YES");
  for (i = j = 1; qtd >= k && i <= k; j++) {
    if (v[j]) {
      if (i > 1) printf(" ");
      printf("%d", v[j]);
      i++;
    }}
  printf("\n");
  return 0;
}
