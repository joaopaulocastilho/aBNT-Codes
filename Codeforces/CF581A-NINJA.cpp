#include <stdio.h>

int main(void){
  int r, b, ana = 0, anb = 0;

  scanf("%d %d", &r, &b);

  while(r && b){ r--; b--; ana++; }
  while(r >= 2) { r -= 2; anb++; }
  while(b >= 2) { b -= 2; anb++; }

  printf("%d %d\n", ana, anb);
  
  return 0;
}
