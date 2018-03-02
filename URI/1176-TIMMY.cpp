#include <cstdio>
#include <cstring>

#define MAX 112

long long int memo[MAX];

long long int fib(long long int num){
  if(memo[num] != -1) return memo[num];
  return memo[num] = fib(num-1) + fib(num-2);
}
int main(void){
  long long int num, tc;
  memset(memo, -1, sizeof(memo));
  memo[0] = 0;
  memo[1] = 1;
  scanf("%lld", &tc);
  while(tc--){
    scanf("%lld", &num);
    printf("Fib(%lld) = %lld\n", num, fib(num));
  }
  return 0;
}
