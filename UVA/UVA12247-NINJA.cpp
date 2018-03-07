#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 60

int cmp( const void *a, const void *b){
  return *(int *)b - *(int *)a;
}

int main(void){
  int princess[3], prince[3], taken[3], princeb[3], big, x, y, z, i, j, cards[MAX];
  
  while(scanf("%d %d %d %d %d", &princess[0], &princess[1], &princess[2], &prince[0], &prince[1]), princess[0]){
    memset(cards, 0, sizeof(cards));
    cards[princess[0]] = cards[princess[1]] = cards[princess[2]] = cards[prince[0]] = cards[prince[1]] = 1;
    qsort(princess, 3, sizeof(int), &cmp);
    for(z = 1; z <= 52; z++){
      if(cards[z]) continue;
      //printf("Considerando %d\n", z);
      prince[2] = z;
      for(i = 0; i < 3; i++) princeb[i] = prince[i];
      qsort(princeb, 3, sizeof(int), &cmp);

      //for(i = 0; i < 3; i++) printf("%d %d\n", princess[i], princeb[i]);
      //printf("\n");
      
      memset(taken, 0, sizeof(taken));
      for(big = i = 0; i < 3; i++){
	for(j = 0; j < 3; j++){
	  if(princess[i] > princeb[j] && !taken[j]){ big++; taken[j] = 1; break; }
	}
      }
      if(big < 2){ printf("%d\n", z); break; }
    }
    if(big >= 2) printf("-1\n");
  }
  
  return 0;
}
