#include <stdio.h>
#include <math.h>

int main(void){
  int n, resp;

  while(scanf("%d", &n) != EOF){
    resp = 0;
    while(n /= 2) resp++;
    printf("%d\n", resp);
  }

  return 0;
}
