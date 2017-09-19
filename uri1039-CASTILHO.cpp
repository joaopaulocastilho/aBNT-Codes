#include <stdio.h>
#include <math.h>
typedef struct{
  int raio;
  int x;
  int y;
}circulo_t;

int quadrado(int a){
  return a*a;
}
  
int pertence_circulo(circulo_t a, circulo_t b){
  double dist_in;
  int dist;
  dist_in = sqrt(quadrado(a.x-b.x) + quadrado(a.y-b.y));
  dist = ceil(dist_in);
  //if(dist > a.raio) return 0;
  if(dist+b.raio > a.raio) return 0;
  return 1;
}

int main(void){
  circulo_t pessoa, flor;
  while(scanf("%d%d%d%d%d%d", &pessoa.raio, &pessoa.x, &pessoa.y, &flor.raio, &flor.x, &flor.y) != EOF){
    if(pertence_circulo(pessoa, flor)) printf("RICO\n");
    else printf("MORTO\n");
  }
  return 0;
}
