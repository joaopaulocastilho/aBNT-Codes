#include <stdio.h>
#include <string.h>

#define MAX 112345

int v[MAX], cont[MAX], ft[MAX];

int main(void) {
  int n, m, ant = 0, i, a, b;
  memset(cont, 0, sizeof(cont)); ft[0] = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = 1; i <= n; i++) {
    if (v[i] > 100007) continue;
    cont[v[i]]++;
    if (cont[v[i]] - 1 == v[i]) ant--;
    else if(cont[v[i]] == v[i]) ant++;
    ft[i] = ant;
  }
  for (i = 1; i <= n; i++) printf("%d ", ft[i]);
  printf("\n");
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", ft[b] - ft[a]);
    }
  return 0;
}
