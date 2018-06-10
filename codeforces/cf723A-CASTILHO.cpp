#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void) {
  int x1, x2, x3, resp;
  scanf("%d %d %d", &x1, &x2, &x3);
  resp = abs(x2 - x1) + abs(x3 - x1);
  resp = min(resp, abs(x1 - x2) + abs(x3 - x2));
  resp = min(resp, abs(x1 - x3) + abs(x2 - x3));
  printf("%d\n", resp);
  return 0;
}
