#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int a, b, c, resp;
  scanf("%d %d %d", &a, &b, &c);
  resp = a + b + c;
  resp = max(resp, (a + b) * c);
  resp = max(resp, a * (b + c));
  resp = max(resp, a + b * c);
  resp = max(resp, a * b + c);
  resp = max(resp, a * b * c);
  printf("%d\n", resp);
  return 0;
}
