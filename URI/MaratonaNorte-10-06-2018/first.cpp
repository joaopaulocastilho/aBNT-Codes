#include <stdio.h>

using namespace std;

#define MAX 50

int main(void) {
  int v[MAX], n, i;
  scanf("%d", &n);
  v[0] = 1; v[1] = 1;
  for (i = 2; i < n; i++)
    v[i] = v[i - 1] + v[i - 2];
  for (i = n - 1; i >= 0; i--) {
    if (i < n - 1) printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
