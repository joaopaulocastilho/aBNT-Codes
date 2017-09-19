#include <stdio.h>

#define MAX 112

int n, a, d, h, x[MAX], y[MAX], z[MAX];

int PD(int i, int somaa, int somad, int somah, int cont){
  if(i==n) return 0;
  if(i==n-1 && (x[i] + somaa != a ||
	      y[i] + somad != d ||
	      z[i] + somah != h)) return 0;
  if(x[i] + somaa == a &&
     y[i] + somad == d &&
     z[i] + somah == h &&
     cont >= 2) return 1;
  if(x[i] + somaa > a ||
     y[i] + somad > d ||
     z[i] + somah > h) return PD(i+1, somaa, somad, somah, cont);
  return PD(i+1, somaa, somad, somah, cont) || PD(i+1, somaa+x[i], somad+y[i], somah+z[i], cont+1);
}

int main(void){
  int i;
  scanf("%d%d%d%d", &n, &a, &d, &h);
  for(i=0; i<n; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
  if(PD(0, 0, 0, 0, 1)) printf("Y\n");
  else printf("N\n");
  return 0;
}
