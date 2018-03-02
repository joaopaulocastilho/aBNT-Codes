#include <cstdio>


int main(void){
  int numero, count = 0, tea;
  scanf("%d", &numero);
  for(int i = 0; i < 5; i++){
    scanf("%d", &tea);
    if(tea == numero) count++;
  }
  printf("%d\n", count);

  return 0;
}
