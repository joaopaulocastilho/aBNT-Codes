#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 1123456

int p[MAX];

int main(void) {
  int n, resp, k, i;
  scanf("%d", &n); resp = n;
  for (i = 0; i < n; i++) scanf("%d", &p[i]);
  for (k = 0, i = n - 1; i >= 0; i--) {
    if (k) resp--;
    k = max(k - 1, p[i]);
  }
  printf("%d\n", resp);
  return 0;
}
