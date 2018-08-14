#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int n, resp = 0;
  while (scanf("%d", &n), n) resp = max(resp, n);
  printf("%d\n", resp);
  return 0;
}
