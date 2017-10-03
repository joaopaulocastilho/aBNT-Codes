#include<stdio.h>
#include<string.h>

#define MAX 112345

int n, ft[MAX];

int rsq(int i) {
  int ret;
  if (i == 0) return 0;
  for (ret = 0; i > 0; i -= (i & -i)) ret += ft[i];
  return ret;
}

void update(int i, int v) { for ( ; i <= n; i += (i & -i)) ft[i] += v; }

int main(void) {
  int i, bug[MAX], x;
  char o;
  scanf("%d", &n);
  memset(ft, 0, sizeof(ft));
  for (i = 1; i <= n; i++) {
    scanf("%d", &bug[i]);
    update(i, bug[i]);
  }
  while (scanf(" %c %d", &o, &x) != EOF) {
    if (o == 'a') update(x, -bug[x]);
    else printf("%d\n", rsq(x - 1));
  }
  return 0;
}
