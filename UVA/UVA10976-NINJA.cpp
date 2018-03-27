#include <stdio.h>

#define EPS 10e-9

#define MAX 1123
#define INF 112356789

typedef struct{
  int x, y;
}xy_t;

int main(void){
  int qtd, y, i;
  xy_t ans[MAX];
  double k, x;
  
  while(scanf("%lf", &k) != EOF){
    for(x = INF, qtd = 0, y = k+1; y <= x; y++){
      // printf("%d\n", y);
      x = (k*y)/(y-k);
      //if(y > x || y < 0) continue;
      if(x - (int)x < EPS){ ans[qtd].x = (int)x; ans[qtd++].y = y; }
    }
     printf("%d\n", qtd);
    for(i = 0; i < qtd; i++)
      printf("1/%.0lf = 1/%d + 1/%d\n", k, ans[i].x, ans[i].y);
  }
  return 0;
}
