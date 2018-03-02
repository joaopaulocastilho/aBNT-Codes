#include <cstdio>

int main(void){
  int valor1, valor2;
  while(scanf("%d %d", &valor1, &valor2), valor1 != valor2)
    printf("%s\n", valor1 > valor2 ? "Decrescente" : "Crescente");
  return 0;
}
