#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int a[6], b[6], ans, i;
  while (scanf("%d", &a[0]) != EOF) {
    for (i = 1; i < 5; i++) scanf("%d", &a[i]);
    for (i = 0; i < 5; i++) scanf("%d", &b[i]);
    for (ans = 1, i = 0; i < 5; i++) ans &= (a[i] ^ b[i]);
    printf("%c\n", ans ? 'Y' : 'N');
  }
  return 0;
}
