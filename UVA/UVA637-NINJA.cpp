#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, k, end, n, sheets;
  
  while(scanf("%d", &n), n){
    sheets = ceil((double)n / 4);
    end = n;
    printf("Printing order for %d pages:\n", n);
    for(j = sheets * 4, i = k = 1; end; k += i % 2 ? 0 : 1, i++, j--, end -= 2){
      printf("Sheet %d, %s: ", k, i % 2 ? "front" : "back ");
      if(i % 2){
	if(j > n) printf("Blank, ");
	else printf("%d, ", j);
      }
      else printf("%d, ", i);
      if(i % 2) printf("%d", i);
      else if(j > n) printf("Blank");
      else printf("%d", j);
      printf("\n");
      if(j > n) end++;
    }
  }
  
  return 0;
}
