#include <stdio.h>

int main(void){
  int a, b;

  scanf("%d %d", &a, &b);
  if(b <= 2) printf("nova\n");
  else if(b >= 3 && b <= 96 && b > a) printf("crescente\n");
  else if(b >= 97) printf("cheia\n");
  else printf("minguante\n");
}
