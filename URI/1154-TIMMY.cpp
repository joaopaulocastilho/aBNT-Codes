#include <cstdio>

int main(void){
  double valor, total = 0;
  int count = 0;
  while(scanf("%lf", &valor), valor >= 0){
    total += valor;
    count++;
  }
  printf("%.2lf\n", total/count);
  return 0;
}
