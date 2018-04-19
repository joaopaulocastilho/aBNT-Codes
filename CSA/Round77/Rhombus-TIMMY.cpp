#include <cstdio>

double troca(double d1, double d2, double ori){
  int area = (d1*d2)/2;
  while(d1 > ori){
    d1--; d2++;
    if((d1*d2)/2 > area) area = (d1*d2)/2;
  }
  return area;
}


int main(void){
  double ans;
  double d1, d2;
  int k;
  scanf("%lf %lf %d", d1, d2, k);
  if(d1 > d2){
    ad1 += k;
    ans = troca(ad1, d2, d1);
  }
  else{
    ad2 += k;
    ans = troca(ad2, d1, d2);
  }
  printf("%lf\n", ans;
  return 0;
}
