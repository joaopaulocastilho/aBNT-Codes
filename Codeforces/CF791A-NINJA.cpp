#include <stdio.h>

int main(void){
  int ans,bear = 0, brother = 0;

  scanf("%d %d", &bear, &brother);
  for(ans = 0; bear <= brother; bear *= 3, brother *= 2, ans++);
  printf("%d\n", ans);
  
  return 0;
}
