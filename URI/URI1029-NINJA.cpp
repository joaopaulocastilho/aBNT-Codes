#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct{
  int num, calls;
}fibo_t;

fibo_t fibo[MAX];

int fib(int x){
  if(fibo[x].num != -1) return fibo[x].num;
  fibo[x].num = fib(x-1) + fib(x-2);
  fibo[x].calls = fibo[x-1].calls + fibo[x-2].calls + 1;
  return fibo[x].num;
}

int main(void){
  int n, x;

  memset(fibo, -1, sizeof(fibo));
  fibo[0].num = 0; fibo[1].num = 1;
  fibo[0].calls = fibo[1].calls = 1;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &x);
    fib(x);
    printf("fib(%d) = %d calls = %d\n", x, fibo[x].calls - 1, fibo[x].num);
  }
  
  return 0;
}
