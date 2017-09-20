#include <stdio.h>
#include <math.h>

#define SQR(a) (a)*(a)

int main(void){
  int xf, yf, xi, yi, vi, r1, r2;
  double dist;

  while(scanf("%d %d %d %d %d %d %d", &xf, &yf, &xi, &yi, &vi, &r1, &r2) != EOF){
    dist = sqrt(SQR(xf - xi) + SQR(yf - yi)); //distancia inicial
    dist += vi * 1.5; // quanto o invasor anda no tempo de canalização
    if(dist <= r1 + r2) printf("Y\n"); //se a distancia for no máximo o raio, acerta
    else printf("N\n");
  }
  return 0;
}
