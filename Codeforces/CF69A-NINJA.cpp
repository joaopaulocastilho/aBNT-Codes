#include <stdio.h>

int main(void){
  int n, x, y, z, xs = 0, ys = 0, zs = 0;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d %d", &x, &y, &z);
    xs += x; ys += y; zs += z;
  }
  printf("%s\n", (!xs && !ys && !zs) ? "YES" : "NO");

  return 0;
}
