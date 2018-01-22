#include <stdio.h>

char nomes[][20] = {"Rudolph", "Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen"};

int main(void){
  int i, num, sum = 0;

  for(i = 0; i < 9; i++){
    scanf("%d", &num);
    sum += num;
  }
  printf("%s\n", nomes[sum % 9]);
  return 0;
}
