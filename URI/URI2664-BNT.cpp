#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX 112345

int t, min, max, memo[112][MAX];

int pd(int time, int level){
  if(time == t) return 1;
  if(memo[time][level] != -1) return memo[time][level];
  if(level == min) return memo[time][level] = pd(time+1, level+1) % MOD;
  if(level == max) return memo[time][level] = pd(time+1, level-1) % MOD;
  return memo[time][level] = (pd(time+1, level-1) % MOD + pd(time+1, level+1) % MOD) % MOD;
}

int main(void){
  int i;
  int ans = 0;
  
  memset(memo, -1, sizeof(memo));
  scanf("%d %d %d", &t, &min, &max);
  for(i = min; i <= max; i++) ans = (ans + (pd(1, i) % MOD)) % MOD;
  printf("%d\n", ans % MOD);
  return 0;
}
