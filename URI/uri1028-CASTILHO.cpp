#include <stdio.h>

int mdc(int a, int b){
  if(!b) return a;
  return mdc(b, a%b);
}

int main(void){
  int a, b, n;
  scanf("%d", &n);
  while(n--){
    scanf("%d%d", &a, &b);
    printf("%d\n", mdc(a, b));
  }
  return 0;
}
