#include <cstdio>

int main(void){
  int valor, count = 1;
  scanf("%d", &valor);
  for(int i = valor; i > 1; i--)
    count = count * i;
  printf("%d\n", count);
  return 0;
}
