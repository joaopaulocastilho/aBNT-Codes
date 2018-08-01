#include <stdio.h>

int main(void){
  int g1, s1, b1, g2, s2, b2;

  scanf("%d %d %d", &g1, &s1, &b1);
  scanf("%d %d %d", &g2, &s2, &b2);

  if(g1 == g2){
    if(s1 == s2){
      if(b1 > b2) printf("A\n");
      else printf("B\n");
    }
    else if(s1 > s2) printf("A\n");
    else printf("B\n");
  }
  else if(g1 > g2) printf("A\n");
  else printf("B\n");
  
  return 0;
}
