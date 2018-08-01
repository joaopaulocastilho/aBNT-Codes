#include <stdio.h>

#define MAX 11
#define INF 112345678

int main(void){
  int i;
  double ttl, notas[MAX], mai, men;

  for(mai = -INF, men = INF, i = 0; i < 5; i++){
    scanf("%lf", &notas[i]);
    ttl += notas[i];
    if(notas[i] > mai) mai = notas[i];
    if(notas[i] < men) men = notas[i];
  }
  printf("%.1lf\n", ttl - mai - men);
  
  return 0;
}
