#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
  int h, m;
  double ph, dist;

  while(scanf("%d:%d", &h, &m), h){
    ph = (h * 5) + (double)m/12; 
    dist = max(ph, (double)m) - min(ph, (double)m);
    printf("%.3lf\n", min(dist, 60-dist) * 6);
  }
  
  return 0;
}
