#include <stdio.h>

int main(void) {
  int num, den;
  double resp = 1;
  for (num = 3, den = 2; num <= 39; num +=2, den *= 2)
    resp += (double)num / (double)den;
  printf("%.2lf\n", resp);
  return 0;
}
