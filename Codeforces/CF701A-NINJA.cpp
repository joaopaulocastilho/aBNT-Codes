#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, n, sum, avg, cards[MAX], taken[MAX];

  memset(taken, 0, sizeof(taken));
  scanf("%d", &n);
  for(sum = i = 0; i < n; i++){
    scanf("%d", &cards[i]);
    sum += cards[i];
  }
  avg = sum/n;
  for(i = 0; i < n; i++){
    if(taken[i]) continue;
    printf("%d ", i+1);
    for(j = i+1; j < n; j++)
      if(!taken[j] && cards[i] + cards[j] == 2*avg){	
	printf("%d\n", j+1);
	taken[i] = taken[j] = 1;
	break;
      }
  }

  return 0;
}
