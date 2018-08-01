#include <stdio.h>

#define M 1000000
#define N 2*1000000000

int main(void){
  int alfa, beta, ai, bi, ci, di;

  for(ai = 1; ai <= 2000; ai++){
    if(ai*ai*ai*ai > N) continue;
    for(bi = ai; bi <= 2000-ai; bi++){
      if(ai*bi*bi*bi > N) continue;
      for(ci = bi; ci <= 2000-ai-bi; ci++){
	if(ai*bi*ci*ci > N) continue;
	alfa = ai + bi + ci;
	beta = ai * bi * ci;
	if(beta == M) continue;
	if((alfa*M)%(beta-M)) continue;
	di = (alfa*M)/(beta-M);
	if(ci > di) continue;
	if(alfa + di > 2000) continue;
	if(beta * di > N) continue;
	printf("%.2lf %.2lf %.2lf %.2lf\n", (double)ai/100, (double)bi/100, (double)ci/100, (double)di/100); 
      }
    }
  }
  
  return 0;
}
