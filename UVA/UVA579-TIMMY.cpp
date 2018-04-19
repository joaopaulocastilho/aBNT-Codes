#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
  double ghora;
  double gmin;
  double ans;
  int h, m;

  while(scanf("%d:%d", &h, &m), h != 0 || m != 0){
    ghora = h * 30 + (double)m/2;
    gmin = 6 * m;
    ans = min(abs(gmin - ghora), 360 - abs(gmin - ghora));
    printf("%.3lf\n", ans);
  }
  return 0;
}
