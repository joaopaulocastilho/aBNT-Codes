#include <stdio.h>

#define MAX 112345
#define INF 1123456789

int qtd, n, sum, ind, inda, tracks[MAX], tmp[MAX], ans[MAX];

void bt(int i, int t){
  int j;
  //printf("(%d, %d)-> ", i, t); for(int x = 0; x < ind; x++) printf("%d ", tmp[x]); printf("\n");
  if(t > n) return;
  if(i >= qtd){
    if(t > sum){
      sum = t; inda = ind;
      for(j = 0; j < ind; j++)
	ans[j] = tmp[j];
    }
    return;
  }
  tmp[ind++] = tracks[i];
  bt(i + 1, t + tracks[i]); ind--;
  bt(i + 1, t);
}

int main(void){
  int i;

  while(scanf("%d", &n) != EOF){
    scanf("%d", &qtd);
    for(i = 0; i < qtd; i++) scanf("%d", &tracks[i]);
    sum = ind = 0;  bt(0, 0);
    for(i = 0; i < inda; i++) printf("%d ", ans[i]);
    printf("sum:%d\n", sum);
  }
  
  return 0;
}
