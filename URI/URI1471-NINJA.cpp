#include <stdio.h>
#include <string.h>

#define MAX 11234

int main(void){
  int i, n, r, surv, merg[MAX];

  while(scanf("%d %d", &n, &r) != EOF){
    memset(merg, 0, sizeof(merg));
    for(i = 0; i < r; i++){
      scanf("%d", &surv);
      merg[surv] = 1;
    }
    if(n == r){ printf("*\n"); continue; }
    for(i = 1; i <= n; i++)
      if(!merg[i]) printf("%d ", i);
    printf("\n");
  }

  return 0;
}
