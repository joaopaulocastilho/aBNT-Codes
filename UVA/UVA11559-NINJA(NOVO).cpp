#include <stdio.h>

#define INF 1123456789

int main(void){
  int n, b, h, w, i, hprice, disp, best;

  while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
    best = INF;
    while(h--){
      scanf("%d", &hprice);
      for(i = 0; i < w; i++){
	scanf("%d", &disp);
	//printf("Considerando disp %d e preço%d\n", disp, hprice);
	if(disp >= n && (n * hprice <= best)) best = n * hprice;
      }
    }
    if(best <= b) printf("%d\n", best);
    else printf("stay home\n");
  }

  return 0;
}
