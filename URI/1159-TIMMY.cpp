#include <cstdio>

int main(void){
  int num;
  while(scanf("%d", &num), num != 0){
    int ans = 0;
    for(int i = 0; i < 5; num++)
      if(num % 2 == 0){ ans+= num; i++; }
    printf("%d\n", ans);
  }
  return 0;
}
