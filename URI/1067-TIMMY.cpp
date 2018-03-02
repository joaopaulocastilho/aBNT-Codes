#include <cstdio>

int main(void){
  int valor;
  scanf("%d", &valor);
  for(int i = 1; i <= valor; i++) if(i % 2 != 0) printf("%d\n", i);
  return 0;
}
