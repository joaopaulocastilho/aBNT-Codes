#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void) {
  int n, cont, mc, tim, i, first;
  scanf("%d", &n);
  vector <int> t(n);
  for (i = 0; i < n; i++) scanf("%d", &t[i]);
  scanf("%d", &tim);
  sort(t.begin(), t.end());
  for (first = 1, mc = cont = i = 0; i < n - 1; i++) {
    if (t[i + 1] - t[i] <= tim) {
      cont++;
      if (first) { first = 0; cont++; }
      //printf("%d %d %d\n", t[i + 1], t[i], cont);
    } else {
      if (cont > mc) mc = cont;
      cont = 0;
      first = 1;
    }
  }
  printf("%d\n", mc);
  return 0;
}
