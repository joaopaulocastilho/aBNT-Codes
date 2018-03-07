#include <stdio.h>

int main(void){
  int n, ano1, ano2, inte;
  long double taxa1, taxa2, flutu;
  
  scanf("%d", &n);
  while(n--){
    scanf("%d %Lf %d %Lf", &ano1, &taxa1, &ano2, &taxa2);
    flutu = (taxa2 - taxa1) / (ano2 - ano1);
    inte = flutu;
    flutu -= inte;
    printf("%d,%.02d\n", inte, (int)(flutu*100));
  }

  return 0;
}
