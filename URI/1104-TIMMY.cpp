#include <stdio.h>
#include <string.h>

#define MAX 112345

int main(void){
   int a, b, countx, county, tx[MAX], ty[MAX], temp, max;
   while(scanf("%d %d", &a, &b) && (a != 0 || b != 0)){
      memset(tx, 0, sizeof(tx));
      memset(ty, 0, sizeof(tx));
      countx = county = 0;
      for(int i = 0; i < a; i++){
         scanf("%d", &temp);
         tx[temp] = 1;
      }
      for(int i = 0; i < b; i++){
         scanf("%d", &temp);
         ty[temp] = 1;
      }
      for(int i = 0; i < MAX; i++){
         if(tx[i] == 1 && ty[i] == 0) countx++;
         if(ty[i] == 1 && tx[i] == 0) county++;
      }
      printf("%d\n", countx > county ? county : countx);
   }
   return 0;
}
