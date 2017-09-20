#include <stdio.h>
#include <string.h>

#define MAXC 51
#define MAXP 2123

int LG[MAXC][MAXP], size[MAXC], visitado[MAXC];
int c, p;

void dfs(int n, int a, int b){
  int i;
  visitado[n]=1;
  for(i=0; i<size[n]; i++){
    if(!visitado[LG[n][i]]
       && !(n==a && b==LG[n][i]) && !(LG[n][i]==a && b==n))
      dfs(LG[n][i], a, b);
  }}

int main(void){
  int i, j, x, y, flag, a[MAXP], b[MAXP], cont;
  while(scanf("%d%d", &c, &p) != EOF){
    memset(size, 0, sizeof(size)); cont=0;
    for(i=0; i<p; i++){
      scanf("%d%d", &x, &y);
      LG[x][size[x]++]=y;
      LG[y][size[y]++]=x;
      a[i]=x; b[i]=y;
    }
    for(i=0; i<p; i++){
      memset(visitado, 0, sizeof(visitado)); flag=1;
      dfs(1, a[i], b[i]);
      for(j=1; flag && j<=c; j++)
        if(!visitado[j]){ cont++; flag=0; }
    }
    printf("%d\n", cont);
  }
  return 0;
}
