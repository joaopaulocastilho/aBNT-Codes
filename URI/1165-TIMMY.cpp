#include <cstdio>

int main(void){
  int tc, num, flag;
  scanf("%d", &tc);
  while(tc--){
    flag = 1;
    scanf("%d", &num);
    for(int i = 2; i <= (num+1)/2; i++)
      if(num % i == 0){ flag = 0; break; }
    if(flag) printf("%d eh primo\n", num);
    else printf("%d nao eh primo\n", num);
  }
  return 0;
}
