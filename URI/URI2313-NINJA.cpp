#include <stdio.h>
#include <stdlib.h>

#define SQR(a) (a) * (a)

int main(void){
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  if(!( (a < b+c && a > abs(b-c)) || (b < a+c && b > abs(a-c))
    || (c < a+b && c > abs(b-a))))
    printf("Invalido\n");
  else{
    printf("Valido-");
    if(a == b && b == c) printf("Equilatero\n");
    else if(a == b || b == c || a == c) printf("Isoceles\n");
    else printf("Escaleno\n");
    printf("Retangulo: ");
    if( (SQR(a) == SQR(b) + SQR(c)) || (SQR(b) == SQR(a) + SQR(c))
      || (SQR(c) == SQR(b) + SQR(a)))
      printf("S\n");
    else printf("N\n");
  }
  return 0;
}
