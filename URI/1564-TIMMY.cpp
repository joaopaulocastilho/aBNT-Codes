#include <cstdio>

int main(void){
  int valor;
  while(scanf("%d", &valor) != EOF)
    if(valor == 0) printf("vai ter copa!\n");
    else printf("vai ter duas!\n");
  return 0;
}
