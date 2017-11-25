#include<stdio.h>
#include<string.h>

#define MAX 112

int main(void) {
  int n, p, q, val, levels[MAX], resp = 1, i;
  memset(levels, 0, sizeof(levels));
  scanf("%d", &n); scanf("%d", &p);
  for (i = 0; i < p; i++) { scanf("%d", &val); levels[val] = 1; }
  scanf("%d", &q);
  for (i = 0; i < q; i++) { scanf("%d", &val); levels[val] = 1; }
  for (i = 1; i <= n; i++) resp &= levels[i];
  printf("%s\n", resp ? "I become the guy." : "Oh, my keyboard!");
  return 0;
}
