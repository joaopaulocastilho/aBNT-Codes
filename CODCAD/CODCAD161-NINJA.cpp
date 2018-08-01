#include <stdio.h>
#include <stdlib.h>

#define MAX 1123

int main(void){
  int i, j, k, n, b, balls[MAX], pos, ans;

  while(scanf("%d %d", &n, &b), n || b){
    for(i = 0; i < b; i++) scanf("%d", &balls[i]);
    for(ans = 1, i = 0; i <= n; i++){
      for(pos = j = 0; j < b && !pos; j++)
	for(k = 0; k < b && !pos; k++)
	  if(abs(balls[j] - balls[k]) == i) pos = 1;
      if(!pos) {ans = 0; break;}
    }
    printf("%s\n", ans ? "Y" : "N"); 
  }

  return 0;
}
