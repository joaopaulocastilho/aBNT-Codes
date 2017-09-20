#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int c, m, t, s, p, e;

int cmpf(double a, double b){
	if (fabs(a-b) < EPS) return 0;
	return 1;
}

void calcula_unidades(double x, double y, double z){
  int x1, y1, z1;
  x1 = x*1000; y1 = y*1000; z1 = z*1000;
  c = round(x1/5);
  y1 -= 25*c; z1 -= 20*c;
  m = round(y1/25);
  z1 -= 25*m;
  t = round(z1/50);
}

void calcula_caixas(){
  s = round(t/10.0);
  m -= 10*s; c -= 10*s;
  p = round(m/20.0);
  c -= 10*p;
  e = round(c/30.0);
}

int main(void){
  double x, y, z;
  int cont=0;
  while (scanf("%lf %lf %lf", &x, &y, &z)!=EOF && (cmpf(x, 0) || cmpf(y, 0) || cmpf(z, 0))){
    cont++;
    if(x && y && z){
      calcula_unidades(x, y, z);
      calcula_caixas();
      printf("Caso #%d: %d Especial, %d Predileta e %d Sortida\n", cont, e, p, s);
    }
  }
  return 0;
}
