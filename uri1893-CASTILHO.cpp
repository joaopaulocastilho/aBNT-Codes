#include <stdio.h>

int main(void){
  int n1, n2;
  scanf("%d%d", &n1, &n2);
  if(n1 >= 0 && n2 <= 2) printf("nova\n");
  else if(n2 >= 97) printf("cheia\n");
  else if(n1>n2) printf("minguante\n");
  else printf("crescente\n");
  
  return 0;
}
