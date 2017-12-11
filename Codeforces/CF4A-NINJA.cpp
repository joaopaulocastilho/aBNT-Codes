#include <stdio.h>

int main(void){
  int i, w;

  scanf("%d", &w);
  printf("%s\n", w <= 2 || w % 2? "NO" : "YES");
  
  return 0;
}
