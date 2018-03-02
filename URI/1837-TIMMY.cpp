#include <cstdio>
#include <cstdlib>

int main(void){
  int a, r, q, b, mod;
  scanf("%d %d", &a, &b);
  mod = abs(b);
  q = -1000;
  r = -b * q + a;
  while(r < 0 || r >= mod){
    q++;
    r = -b * q + a;
  }
  printf("%d %d\n", q, r);
  return 0;
}
