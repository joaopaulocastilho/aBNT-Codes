#include <stdio.h>

int main(void){
   int peso, a, b, flag;
   while (scanf("%d", &peso) != EOF){
      a = 1; b = --peso; flag = 1;
      while(b >= a){
         if(a % 2 == 0 && b % 2 == 0){
            printf("YES\n");
            flag = 0;
            break;
         }
         a++; b--;
      }
      if(flag) printf("NO\n");
   }
   return 0;
}
