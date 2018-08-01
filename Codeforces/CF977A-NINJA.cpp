#include <stdio.h>

int main(void){
  int n, k;

  scanf("%d %d", &n, &k);
  while(k--){
    if(n % 10) n--;
    else n /= 10;
  }
  printf("%d\n", n);

  return 0;
}
