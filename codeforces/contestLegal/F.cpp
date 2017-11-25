#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 112345

int main(void) {
  int x[MAX], n, i, cont = 0;
  scanf("%d", &n);
  vector<int>v(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    x[i] = v[i];
  }
  sort(v.begin(), v.end());
  for (i = 0; i < n; i++) {
    if (v[i] != x[i]) cont++;
  }
  if (cont > 2) printf("NO\n");
  else printf("YES\n");
  return 0;
}
