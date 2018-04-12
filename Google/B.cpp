#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 112345

void trouble_sort(int v[], int n) {
  int i, done = 0;
  while (!done) {
    done = 1;
    for (i = 0; i < n - 2; i++) {
      if (v[i] > v[i + 2]) {
        done = false;
        swap(v[i], v[i + 2]);
      }}}}

int main(void) {
  int t, caso, n, i, v[MAX], flag;
  scanf("%d", &t);
  for (caso = 1; caso <= t; caso++) {
    printf("Case #%d: ", caso);
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    trouble_sort(v, n);
    for (flag = 1, i = 1; i < n; i++)
      if (v[i - 1] > v[i]) { flag = 0; break; }
    if (flag) printf("OK\n");
    else printf("%d\n", i - 1);
  }
  return 0;
}
