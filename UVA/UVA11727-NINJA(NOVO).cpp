#include <stdio.h>

int main(void){
  int t, a, b, c, i, j, num, mai, smai;
  
  scanf("%d", &t);
  for(i = 1; i <= t; i++){
    mai = smai = -1;
    for(j = 0; j < 3; j++){
      scanf("%d", &num);
      if(num > mai) {smai = mai; mai = num;}
      else if(num > smai) smai = num;
    }
    printf("Case %d: %d\n", i, smai);
  }
  return 0;
}
