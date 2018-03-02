#include <cstdio>

int main(void){
  int tc, valor, total;
  double coelho = 0, rato = 0, sapo = 0;
  char animal;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %c", &valor, &animal);
    if(animal == 'C') coelho += valor;
    if(animal == 'R') rato += valor;
    if(animal == 'S') sapo += valor;
  }
  total = coelho+rato+sapo;
  printf("Total: %d cobaias\n",(int) total);
  printf("Total de coelhos: %d\n", (int)coelho);
  printf("Total de ratos: %d\n", (int)rato);
  printf("Total de sapos: %d\n", (int)sapo);
  printf("Percentual de coelhos: %.2f %c\n", (coelho/total) * 100, '%');
  printf("Percentual de ratos: %.2f %c\n", (rato/total) * 100, '%');
  printf("Percentual de sapos: %.2f %c\n", (sapo/total) * 100, '%');
  
  return 0;
}
