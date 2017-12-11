#include <stdio.h>

#define MAX 100

int main(void){
  int n;
  double a, b, ant;

  while(scanf("%d", &n) != EOF){
    ant = -1;
    for(int i = 1; i <= n; i++){
      scanf("%lf %lf", &a, &b);
      if(b/a > ant){
        ant = b/a;
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
