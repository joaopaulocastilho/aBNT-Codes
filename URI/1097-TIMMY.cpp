#include <cstdio>

#include <cmath>

int compD(double a, double b) {
    if (std::fabs(a - b) < 0.0001) {
        return 0;
    } else if ( a < b ) {
        return -1;
    } else {
        return 1;
    }
}

int main(void){
  
  for(double i = 0, beta = 0; compD(i, 2.0) <= 0; i+= 0.2, beta+=0.2)
    for(double j = 1+beta; j <= 3+beta; j++)
      if(compD(i, 0.0) == 0 || compD(i, 1.0) == 0 || compD(i, 2.0) == 0)
	printf("I=%.0lf J=%.0lf\n", i, j);
      else
      printf("I=%.1lf J=%.1lf\n", i, j);
  return 0;
}
