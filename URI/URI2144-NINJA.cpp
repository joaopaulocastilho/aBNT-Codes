#include <stdio.h>

int main(void){
  double w1, w2, r, avg, sum = 0, num = 0;
  
  while(scanf("%lf %lf %lf", &w1, &w2, &r), w1 || w2 || r){
    avg = ((w1 * (1 + (r/30))) + (w2 * (1 + (r/30))))/ 2;
    //printf("%lf\n", avg);
    if(avg < 13) printf("Nao vai da nao\n");
    else if(avg < 14) printf("E 13\n");
    else if(avg < 40) printf("Bora, hora do show! BIIR!\n");
    else if(avg <= 60) printf("Ta saindo da jaula o monstro!\n");
    else printf("AQUI E BODYBUILDER!!\n");
    sum += avg; num++;
  }
  if(sum/num > 40) printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");
  
  return 0;
}
