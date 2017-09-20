#include <stdio.h>

int expo(int a, int b){
  if(!a) return 0;
  if(!b) return 1;
  return a*expo(a, b-1);
}

int main(void){
  int t, c, d, tot;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &c, &d);
    tot = expo(26, c) * expo(10, d);
    if(!d && !c) printf("0\n");
    else printf("%d\n", tot);
  }
  return 0;
}
