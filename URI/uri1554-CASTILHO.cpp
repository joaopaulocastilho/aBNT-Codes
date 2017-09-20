#include <stdio.h>
#include <math.h>

#define INF 112345678
#define EPS -0.01

typedef struct{ int x, y; }bola_t;

double f_dist(bola_t a, bola_t b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(void){
  int c, n, i, pos;
  double dist;
  bola_t bb, b;
  scanf("%d", &c);
  while(c--){
    dist=INF; pos=0;
    scanf("%d%d%d", &n, &bb.x, &bb.y);
    for(i=0; i<n; i++){
      scanf("%d%d", &b.x, &b.y);
      if(f_dist(bb, b) - dist  < EPS){ dist = f_dist(bb, b); pos=i+1; }
    }
    printf("%d\n", pos);
  }
  return 0;
}
