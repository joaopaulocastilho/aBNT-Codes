#include <stdio.h>

int main(void){
  int i, t, n, x, y, first, last, num;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d", &n, &x, &y);
    for(i = 0; i < n; i++){
      scanf("%d", &num);
      if(i == 0) first = num;
      else if(i == n-1) last = num;
    }
    if(x == first && y == last) printf("BOTH\n");
    else if(x == first) printf("EASY\n");
    else if(y == last) printf("HARD\n");
    else printf("OKAY\n");
  }

  return 0;
}
