#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void) {
  int tc, n, first, i, j;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    vector<int>v(n);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end()); first = 1;
    for (i = 0, j = n - 1; i <= j; ) {
      for ( ; j >= i && !(v[j] & 1); j--);// printf("%d ", v[j]);
      //printf("j: %d, %d\n", j, v[j]);
      if (j >= i) {
        if (first) first = 0;
        else printf(" ");
        printf("%d", v[j]);
      }
      j--;
      for ( ; i <= j && !(v[i] & 1); i++);
      //printf("i: %d, %d\n", i, v[i]);
      if (i <= j) {
        if (first) first = 0;
        else printf(" ");
        printf("%d", v[i]);
      }
      i++;
    }
    printf("\n");
  }
  return 0;
}
