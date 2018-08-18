#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int t, v, f;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &v, &f);
    printf("%d\n", 2 - (v - f));
  }
  return 0;
}
