#include <stdio.h>
#define INF 11234
int main(void){
  int n, menor = INF, pessoa, num=0, indice;
  scanf("%d", &n);
  while(n--){
    num++;
    scanf("%d", &pessoa);
    if(pessoa < menor){
      menor = pessoa;
      indice = num;
    }
  }
  printf("%d\n", indice);
  return 0;
}
