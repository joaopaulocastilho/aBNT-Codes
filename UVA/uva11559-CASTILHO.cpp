#include <stdio.h>
#include <algorithm>

using namespace std;

#define INF 1123456789

int main(void) {
  int n, b, h, w, resp, i, price, j, qtt;
  while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
    for (resp = INF, i = 0; i < h; i++) {
      scanf("%d", &price);
      for (j = 0; j < w; j++) {
        scanf("%d", &qtt);
        if (qtt >= n && n * price <= b) resp = min(resp, n * price);
      }}
    if (resp ==  INF) printf("stay home\n");
    else printf("%d\n", resp);
  }
  return 0;
}
