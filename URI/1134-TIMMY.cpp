#include <cstdio>
#include <cstring>

int main(void){
  int valor, cmb[4];
  memset(cmb, 0, sizeof(cmb));
  while(scanf("%d", &valor), valor != 4){
    if(valor >= 1 && valor < 4)
      cmb[valor]++;
  }
  printf("MUITO OBRIGADO\n");
  printf("Alcool: %d\n", cmb[1]);
  printf("Gasolina: %d\n", cmb[2]);
  printf("Diesel: %d\n", cmb[3]);
  return 0;
}
