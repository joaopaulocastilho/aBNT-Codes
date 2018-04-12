#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int n, curr = 0, ai, bi, resp = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &ai, &bi);
    curr -= ai; curr += bi;
    resp = max(resp, curr);
  }
  printf("%d\n", resp);
  return 0;
}
