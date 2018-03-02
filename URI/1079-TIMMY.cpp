#include <cstdio>

int main(void){
  int tc;
  float valor1, valor2, valor3;
  scanf("%d", &tc);
  while(tc--){
    scanf("%f %f %f", &valor1, &valor2, &valor3);
    printf("%.1f\n", (valor1 * 2 + valor2 * 3 + valor3 * 5)/10 );
  }
  return 0;
}
