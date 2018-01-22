#include <stdio.h>

int main(void){
  int rem, a, b;

  scanf("%d %d %d", &rem, &a, &b);
  if(a + b > rem) printf("Deixa para amanha!\n");
  else printf("Farei hoje!\n");
  
  return 0;
}
