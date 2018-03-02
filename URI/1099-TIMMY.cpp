#include <cstdio>

int main(void){
  int valor1, valor2, tc;
  scanf("%d", &tc);
  while(tc--){
    int count = 0;
    scanf("%d %d", &valor1, &valor2);
    if(valor1 > valor2){int aux = valor1; valor1 = valor2; valor2 = aux; }
    for(int i = valor1+1; i < valor2; i++)
      if(i % 2 != 0) count += i;
    printf("%d\n", count);
  }
  return 0;
}
