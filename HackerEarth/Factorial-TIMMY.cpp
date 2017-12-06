#include <cstdio>

int main(void){
  int fat, ans = 1;
  scanf("%d", &fat);
  for(int i = fat; i > 0; i--){
    ans *= i;
  }
  printf("%d\n", ans);
  return 0;
}
