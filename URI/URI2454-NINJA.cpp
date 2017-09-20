#include <stdio.h>

int main(void){
  int p, r;

  scanf("%d %d", &p, &r);
  if(!p) printf("C\n");
  else if(!r) printf("B\n");
  else printf("A\n");

  return 0;
}
