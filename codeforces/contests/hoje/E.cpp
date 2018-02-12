#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void) {
  int n, cont, mc, tim, i, j, at;
  scanf("%d", &n);
  vector <int> t(n);
  for (i = 0; i < n; i++) scanf("%d", &t[i]);
  scanf("%d", &tim);
  sort(t.begin(), t.end());
  for (mc = i = 0; i < n; i++) {
    at = t[i];
    for (cont = 0, j = i; j < n && t[j] - at <= tim; j++, cont++);
    mc = max(mc, cont);
  }
  printf("%d\n", mc);
  return 0;
}
