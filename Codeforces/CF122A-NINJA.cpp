#include <stdio.h>

int lucky(int x){
  for(; x; x /= 10)
    if((x % 10) != 4 && (x % 10) != 7) return 0;
  return 1;
}

int main(void){
  int i, n, ans = 0;

  scanf("%d", &n);
  for(i = n; i >= 4; i--)
    if(n % i == 0 && lucky(i)) {ans = 1; break;}
  printf("%s\n", ans ? "YES" : "NO");
  
  return 0;
}
