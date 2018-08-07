#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n, s1, s2, i, tmp;
  scanf("%d", &n);
  for (s1 = i = 0; i < n; i++) { scanf("%d", &tmp); s1 += tmp; }
  for (s2 = i = 0; i < n; i++) { scanf("%d", &tmp); s2 += tmp; }
  printf("%s\n", s1 >= s2 ? "Yes" : "No");
  return 0;
}
