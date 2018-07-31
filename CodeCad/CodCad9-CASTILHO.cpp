#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int i, p, n, pts;
  scanf("%d %d", &p, &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &pts);
    if (pts < 0) p = max(p + pts, 0);
    else p = min(p + pts, 100);
  }
  printf("%d\n", p);
  return 0;
}
