#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
  int hh, mm;
  double dist, ph;
  while (scanf("%d:%d", &hh, &mm), hh) {
    ph = ((double)hh * 5) + ((double)mm / 12.0);
    dist = max((double)ph, (double)mm) - min((double)ph, (double)mm);
    printf("%.3lf\n", min(dist, 60 - dist) * 6);
  }
  return 0;
}
