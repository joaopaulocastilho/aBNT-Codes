#include <stdio.h>

#define MAX 112

typedef struct{
  int min, max, curr;
  
} day_t;

int main(void){
  
  int i, d, sum, add, maxes = 0, mines = 0, first = 0;
  day_t days[MAX];

  scanf("%d %d", &d, &sum);
  for(i = 0; i < d; i++){
    scanf("%d %d", &days[i].min, &days[i].max);
    days[i].curr = days[i].min;
    maxes += days[i].max; mines += days[i].min;
  }
  if(sum > maxes || sum < mines) printf("NO\n");
  else{
    printf("YES\n");
    sum -= mines;
    for(i = 0; i < d; i++){
      if(sum){
	if(sum > days[i].max - days[i].curr) add = days[i].max - days[i].curr;
	else add = sum;
	days[i].curr += add;
	sum -= add;
      }
      if(!first) first = 1;
      else printf(" ");
      printf("%d", days[i].curr);
    }
    printf("\n");
  }
  return 0;
}
