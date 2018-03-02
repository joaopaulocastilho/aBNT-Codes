#include <cstdio>

int main(void){
  int valor;
  scanf("%d", &valor);
  for(int i = valor, j = 0; j < 6; i++)
    if(i % 2 != 0){
      printf("%d\n", i); j++;
    }
    return 0;
}
