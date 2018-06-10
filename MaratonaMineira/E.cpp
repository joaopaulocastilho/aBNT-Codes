#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 512345

int ft[MAX], n;

int query(int i) {
  int ret;
  if (i == 0) return 0;
  for (ret = 0; i > 0; i -= (i & -i)) ret += ft[i];
  return ret;
}

void update(int i, int v) { for ( ; i <= n; i += (i & -i)) ft[i] += v; }

int main(void) {
  int at, i, tmp;
  scanf("%d", &n);
  memset(ft, 0, sizeof(ft));
  for (i = 0; i < n; i++) {
    scanf("%d", &at);
    tmp = query(at);
    if (i) printf(" ");
    printf("%d", at - tmp);
    update(at, 1);
  }
  printf("\n");
  return 0;
}
