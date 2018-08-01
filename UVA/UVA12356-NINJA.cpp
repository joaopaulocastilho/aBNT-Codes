#include <stdio.h>
#include <string.h>

#define MAX 112345
#define valido(x) (x >= 1 && x <= s)

int main(void){
  int i, j, l, r, b, s, tmp, dead[MAX];

  while(scanf("%d %d", &s, &b), s){
    memset(dead, 0, sizeof(dead));
    while(b--){
      scanf("%d %d", &l, &r);
      dead[l] = r; dead[r] = l;
      i = l-1; j = r+1;
      if(dead[i] && dead[i] != i){
	dead[dead[i]] = r;
	dead[r] = dead[i];
	i = dead[i];
      }
      if(dead[j] && dead[j] != j){
	dead[l] = dead[j];
	dead[dead[j]] = l;
	j = dead[j];
      }
      //for(int w = 1; w <= s; w++) printf("%d ", dead[w]); printf("\n");
      if(!valido(i)) printf("* ");
      else printf("%d ", i);
      if(!valido(j)) printf("*\n");
      else printf("%d\n", j);
    }
    printf("-\n");	  
  }
  
  return 0;
}
