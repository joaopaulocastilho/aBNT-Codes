#include <cstdio>

#define MAX 2*1000000000

int main(void){
  int a, b, c, d, alfa, beta, m;
  m = 1000000;
  for(a = 1; a < 2000; a++){
    if(a*a*a*a > MAX) break;
    for(b = a; b < 2000 - a; b++){
      if(a*b*b*b > MAX) break; 
      for(c = b; c < 2000 - (a+b); c++){
	if(a*b*c*c > MAX) break;
	alfa = a+b+c;
	beta = a*b*c;
	if(beta == m) continue;
	if((alfa*m) % (beta-m) != 0) continue;
	d = (alfa * m) / (beta-m);
	if(c > d) continue;
	if(alfa+d > 2000) continue;
	if(beta*d > MAX) continue;
	printf("%.2lf %.2lf %.2lf %.2lf\n", ((double)a/100), ((double)b/100), ((double)c/100), ((double)d/100));
      }
    }
  }
  return 0;
}
