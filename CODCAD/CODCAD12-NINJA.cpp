#include <stdio.h>

int main(void){
  int p, r;
  char ans;
  
  scanf("%d %d", &p, &r);

  if(p == 1){
    if(r == 1) printf("A\n");
    else printf("B\n");
  }
  else printf("C\n");
  
  return 0;
}
