#include <stdio.h>

int main(void){
   int ok = 0, nok=0, a, n;
   scanf("%d", &n);
   while(n--){
      scanf("%d", &a);
      if(a == 0) ok++; else nok++;
   }
   if(ok > nok) printf("Y\n"); else printf("N\n");
   return 0;
}
