#include <stdio.h>

int fat(int x){
  return x == 0 ? 1 : x * fat(x-1);
}

int main(void){
  int n;

  scanf("%d", &n);
  printf("%d\n", fat(n));

  return 0;
}
