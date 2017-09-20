#include <stdio.h>
#include <math.h>

int eh_primo(int n){
  int raiz, i;
  if(n==2) return 1;
  if(n%2==0 || n<2) return 0;
  raiz = sqrt(n);
  for(i=3; i<=raiz; i+=2){
    if(n%i == 0) return 0;
  }
  return 1;
}

int main(void){
  int num, n;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    eh_primo(num) ? printf("Prime\n") : printf("Not Prime\n");
    }
  return 0;
}
