#include <stdio.h>

int primo(int x){  
  int i;
  for(i = 2; i < x; i++)
    if(x % i == 0) return 0;
  return 1;
}

int main(void){
  int n;

  scanf("%d", &n);
  printf("%s\n", primo(n) ? "S" : "N");

  return 0;
}
