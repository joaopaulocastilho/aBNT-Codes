#include <cstdio>

int main(void){
  double s = 1;
  for(double i = 2, j = 3; j < 40; i = i * 2, j+=2)
    s += j/i;
  printf("%.2lf\n", s);
  return 0;
}
