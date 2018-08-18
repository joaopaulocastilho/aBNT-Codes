#include <bits/stdc++.h>

const int MAX = 112345;

typedef struct{
  int xi, xs, yi, ys, ans;
}ceu_t;

typedef struct{
  int x, y;
}star_t;

int main(void){
  int i, j, c, qtd, x, y;
  ceu_t ceu[12];
  star_t stars[MAX];
  
  memset(ceu, 0, sizeof(ceu));
  scanf("%d", &c);
  for(qtd = i = 0; i < c; i++)
    scanf("%d %d %d %d", &ceu[i].xi, &ceu[i].xs, &ceu[i].yi, &ceu[i].ys);
  while(scanf("%d %d", &x, &y), x || y){
    stars[qtd].x = x;
    stars[qtd++].y = y;
  }
  for(i = 0; i < qtd; i++)
    for(j = 0; j < c; j++){
      if(stars[i].x >= ceu[j].xi && stars[i].x <= ceu[j].xs &&
         stars[i].y >= ceu[j].yi && stars[i].y <= ceu[j].ys) ceu[j].ans++;
    }
  for(i = 0; i < c; i++)
    printf("CEU #%d: %d estrelas\n", i+1, ceu[i].ans);
}
