#include <stdio.h>

int main(void){
  int l, c, i, j, cor = 1;

  scanf("%d %d", &l, &c);
  if(l%2 == c%2) printf("1\n");
  else printf("0\n");
  
  return 0;
}
