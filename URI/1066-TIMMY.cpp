#include <cstdio>

int main(void){
  int valor, par, impar, positivos, negativos;
  par = impar = positivos = negativos = 0;
  for(int i = 0; i < 5; i++){
    scanf("%d", &valor);
    if(valor % 2 == 0) par++;
    else impar++;
    if(valor > 0) positivos++;
    if(valor < 0) negativos++;
  }
  printf("%d valor(es) par(es)\n", par);
  printf("%d valor(es) impar(es)\n", impar);
  printf("%d valor(es) positivo(s)\n", positivos);
  printf("%d valor(es) negativo(s)\n", negativos);
  
  return 0;
}
