#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void) {
  int n, i, st = 0, sat = 0, flag = 1, resp = 0;
  scanf("%d", &n);
  vector<int>m(n);
  for (i = 0; i < n; i++) { scanf("%d", &m[i]); st += m[i]; }
  sort(m.begin(), m.end());
  for (i = n - 1; flag && i >= 0; i--) {
    if (sat > st) { flag = 0; continue; }
    sat += m[i];
    st -= m[i];
    resp++;
  }
  printf("%d\n", resp);
  return 0;
}
