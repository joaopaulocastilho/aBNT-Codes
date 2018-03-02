#include <cstdio>

int main(void){
  int valor, v[10];
  scanf("%d", &valor);
  for(int i = 0; i < 10; valor = 2 * valor, i++){
    v[i] = valor;
    printf("N[%d] = %d\n", i, valor);
  }
  return 0;
}
