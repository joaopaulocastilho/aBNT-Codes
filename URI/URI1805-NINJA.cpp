#include <stdio.h>

typedef long long int llu;

int main(void){
  llu a, b;

  scanf("%lld %lld", &a, &b);
  printf("%lld\n", (((b-a)+1)*(a+b))/2);
  
  return 0;
}
