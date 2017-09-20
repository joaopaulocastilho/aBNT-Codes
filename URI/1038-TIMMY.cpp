#include <stdio.h>


int main(void){
   double a[5];
   int b, c;
   a[0] = 4; a[1]= 4.50; a[2] = 5.0; a[3] = 2.0; a[4]= 1.50;
   scanf("%d %d", &b, &c);
   printf("Total: R$ %.2lf\n", (a[--b] * c));
   return 0;
}
