#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112345

int n, ft[MAX];

int sea(int i) {
  int ret;
  if (i == 0) return 0;
  for (ret = 0; i > 0; i -= (i & -i)) ret += ft[i];
  return ret;
}

void update(int i, int v) { for ( ; i <= n; i += (i & -i)) ft[i] += v; }

int main(void) {
  int k, i, qtd[MAX], comp[MAX], resp = 0, resp2 = 0;
  scanf("%d %d", &n, &k);
  memset(ft, 0, sizeof(ft));
  for (i = 1; i <= n; i++) scanf("%d", &qtd[i]);
  for (i = 1; i <= n; i++) {
    scanf("%d", &comp[i]);
    if (!comp[i]) update(i, qtd[i]);
    else resp2 += qtd[i];
  }
  for (i = n; i >= k; i--) {
    resp = max(resp, sea(i) - sea(i - k));
  }
  printf("%d\n", resp + resp2);
  return 0;
}
