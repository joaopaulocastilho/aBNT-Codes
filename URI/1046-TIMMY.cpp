#include <cstdio>

int main(void){
  int a, b, ans;
  
  scanf("%d %d", &a, &b);
  if(a > b) ans = 24 - a + b;
  else if(a == b) ans = 24;
  else ans = b - a;
  printf("O JOGO DUROU %d HORA(S)\n", ans);  
  return 0;
}
