#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 112
#define MAX2 21

int n, p[MAX], used[MAX2], curr[MAX2];

int prime(int x){
  int i, end = sqrt(x);
  for(i = 2; i <= end; i++)
    if(x % i == 0) return 0;
  return 1;
}

void bt(int qtd){
  int i, sum;

  //printf("---\n");
  //for(i = 0; i < qtd; i++) printf("%s%d", i ? " " : "", curr[i]); printf("\n");
  for(i = 0; i < qtd-1; i++){
    sum = curr[i] + curr[i+1];
    //printf("SUM: %d is %s prime\n", sum, p[sum] ? "" : "not");
    if(!p[sum]) return;
  }
  if(qtd == n && !p[curr[n-1] + curr[0]]) return;
  //printf("Passed the verification\n");
  if(qtd == n){
    for(i = 0; i < n; i++) printf("%s%d", i ? " " : "", curr[i]);
    printf("\n");
    return;
  }
  for(i = 1; i <= n; i++){
    if(!used[i]){
      used[i] = 1;
      curr[qtd] = i;
      bt(qtd+1);
      used[i] = 0;
    }
  }
}

int main(void){
  int i, caso = 1, first = 1;

  memset(p, 0, sizeof(p));
  memset(used, 0, sizeof(used));
  for(i = 1; i < 50; i++) p[i] = prime(i);
  //for(i = 1; i < 50; i++) if(p[i]) printf("%d\n", i);
  while(scanf("%d", &n) != EOF){
    if(first) first = 0;
    else printf("\n");
    printf("Case %d:\n", caso++);
    used[1] = curr[0] = 1;
    bt(1);
  }

  return 0;
}
