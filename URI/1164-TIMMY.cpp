#include <cstdio>

int main(void){
  int tc, num, ans;
  scanf("%d", &tc);
  while(tc--){
    ans = 0;
    scanf("%d", &num);
    for(int i = 1; i <= (num+1)/2; i++)
      if(num % i == 0) ans += i;
    if(ans == num && num != 1) printf("%d eh perfeito\n", num);
    else printf("%d nao eh perfeito\n", num);
  }
  return 0;
}
