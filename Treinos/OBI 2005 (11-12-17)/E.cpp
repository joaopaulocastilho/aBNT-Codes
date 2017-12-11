#include <stdio.h>

int main(void){
  int i, n, a, b, aldo, beto, caso = 1;

  while(scanf("%d", &n), n){
    for(i = aldo = beto = 0; i < n; i++){
      scanf("%d %d", &a, &b);
      aldo += a; beto += b;
    }
    printf("Teste %d\n", caso++);
    printf("%s\n", aldo > beto ? "Aldo" : "Beto");
    printf("\n");
  }

  return 0;
}
