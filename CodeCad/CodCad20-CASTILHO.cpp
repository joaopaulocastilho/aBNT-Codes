#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int i, n, b, resp;
  scanf("%d %d", &n, &resp);
  for (i = 1; i < n; i++) {
    scanf("%d", &b);
    resp = min(resp, b);
  }
  printf("%d\n", resp);
  return 0;
}
