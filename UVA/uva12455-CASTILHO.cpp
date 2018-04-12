#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void) {
  int t, n, p, i, j, resp[MAX], bar[MAX], tmp[MAX];
  scanf("%d", &t);
  while (t--) {
    memset(resp, 0, sizeof(resp)); resp[0] = 1;
    scanf("%d %d", &n, &p);
    for (i = 0; i < p; i++) scanf("%d", &bar[i]);
    for (i = 0; i < p; i++) {
      memset(tmp, 0, sizeof(tmp));
      for (j = 0; j <= n; j++)
	if (resp[j] && bar[i] + j <= n) tmp[bar[i] + j] = 1;
      for (j = 0; j <= n; j++) resp[j] |= tmp[j];
    }
    printf("%s\n", resp[n] ? "YES" : "NO");
  }
  return 0;
}
