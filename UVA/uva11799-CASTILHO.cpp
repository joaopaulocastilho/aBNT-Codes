#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int n, q, c, v, resp;
  scanf("%d", &n);
  for (c = 1; c <= n; c++) {
    scanf("%d", &q);
    scanf("%d", &v); resp = v;
    while (--q) {
      scanf("%d", &v);
      resp = max(resp, v);
    }
    printf("Case %d: %d\n", c, resp);
  }
  return 0;
}
