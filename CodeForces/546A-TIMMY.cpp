#include <cstdio>

int main(void){
   int k, n, w, sum = 0;
   scanf("%d %d %d", &k, &n, &w);
   for(int i = 1; i <= w; i++) sum+= i*k;
   printf("%d\n", sum - n > 0 ? sum - n : 0);
   return 0;
}
