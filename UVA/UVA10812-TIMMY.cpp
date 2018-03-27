#include <cstdio>

int main(void){
  int tc, n, m, a , b;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %d", &n, &m);
    b = (n-m)/2;
    a = n-b;
    if((n + m) % 2 != 0 || (a < 0 || b < 0)){ printf("impossible\n"); continue; }
    printf("%d %d\n", a, b);
  }
  return 0;
}
