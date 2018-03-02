#include <cstdio>
#include <cstring>

#define MAX 112

int memo[MAX];

int fib(int num){
  if(memo[num] != -1) return memo[num];
  return memo[num] = fib(num-1) + fib(num-2);
}
int main(void){
  int num;
  memset(memo, -1, sizeof(memo));
  memo[1] = 0;
  memo[2] = 1;
  scanf("%d", &num);
  for(int i = 1; i <= num; i++)
    printf("%d%c", fib(i), i == num ? '\n' : ' ');
  return 0;
}
