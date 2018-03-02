#include <cstdio>

int main(void){
  int valor;
  scanf("%d", &valor);
  for(int i = 1; i < valor/2+1; i++)
    if(valor % i == 0) printf("%d\n", i);
  printf("%d\n", valor);
  return 0;
}
