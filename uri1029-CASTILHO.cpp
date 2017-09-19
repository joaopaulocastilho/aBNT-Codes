#include <stdio.h>

int cont;

int fib(int n){
  if(n==1) return 1;
  if(n==0) return 0;
  cont+=2;
  return fib(n-1)+fib(n-2);
}

int main(void){
  int n, x;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &x);
    cont=0;
    printf("fib(%d) = %d calls = %d\n", x, cont, fib(x));
  }
  return 0;
}
