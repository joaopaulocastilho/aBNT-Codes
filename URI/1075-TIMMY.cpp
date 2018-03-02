#include <cstdio>

int main(void){
  int valor;
  scanf("%d", &valor);
  for(int i = 1; i <= 10000; i++)
    if(i % valor == 2) printf("%d\n", i);
  return 0;
}
