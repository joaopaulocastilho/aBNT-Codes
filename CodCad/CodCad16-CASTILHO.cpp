#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n, k, p1, p2, resp = 0;
  scanf("%d %d", &n , &k);
  while (n--) {
    scanf("%d %d", &p1, &p2);
    if (p1 + p2 >= k) resp++;
  }
  printf("%d\n", resp);
  return 0;
}
