#include <cstdio>

#define INF 1123456

int main(void){
  int n, b, h, w, cost, bed, menor;
  while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
    menor = INF;
    for(int i = 0; i < h; i++){
      scanf("%d", &cost);
      for(int j = 0; j < w; j++){
	scanf("%d", &bed);
	if(bed >= n){
	  if(cost * n < menor && cost * n < b) menor = (cost * n);
	}
      }
    }
    if(menor == INF) printf("stay home\n");
    else printf("%d\n", menor);
  }
  return 0;
}
