#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int n, xp, yp, num, level[MAX];

  memset(level, 0, sizeof(level));
  scanf("%d", &n);
  scanf("%d", &xp);
  while(xp--){
    scanf("%d", &num);
    if(level[num] == 0){
      level[num] = 1; n--;
    }
  }
  scanf("%d", &yp);
  while(yp--){
    scanf("%d", &num);
    if(level[num] == 0){
      level[num] = 1; n--;
    }
  }
  if(n) printf("Oh, my keyboard!\n");
  else printf("I become the guy.\n");
  
  return 0;
}
