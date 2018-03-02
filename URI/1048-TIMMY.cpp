#include <cstdio>

float ajuste(float salario, int &percentual){

  if(salario <= 400){ percentual = 15; return salario * 0.15; }
  else if(salario <= 800){ percentual = 12; return salario * 0.12; }
  else if(salario <= 1200){ percentual = 10; return salario * 0.1; }
  else if(salario <= 2000) { percentual = 7; return salario * 0.07; }
  else { percentual = 4; return salario * 0.04; }

}

int main(void){
  float salario;
  int percentual;
  scanf("%f", &salario);
  printf("Novo salario: %.2f\n", salario + ajuste(salario, percentual));
  printf("Reajuste ganho: %.2f\n", ajuste(salario, percentual));
  printf("Em percentual: %d %c\n", percentual, '%');

  return 0;
}
