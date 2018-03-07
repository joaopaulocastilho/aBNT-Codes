#include <stdio.h>

int main(void){
  int n, m, i;

  scanf("%d %d", &n, &m);
  for(i = 1; n; i++, n--){
    //printf("Dia %d , %d meias\n", i, n);
    if(i % m == 0) n++;
  }
  printf("%d\n", i-1);
  
}
