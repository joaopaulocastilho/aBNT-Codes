#include <stdio.h>

int main(void){
  int t, ct, lr, ctt, lrt, cla, rem;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d %d %d", &ct, &lr, &ctt, &lrt, &cla);
    rem = 24 - 10 - ct*ctt - lr*lrt - cla;
    //printf("%d\n", rem);
    if(rem >= 3) printf("Khushi\n");
    else printf("Hotash\n");
  }

  return 0;
}
