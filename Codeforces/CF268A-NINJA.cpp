#include <stdio.h>

#define MAX 112

typedef struct{
  int h, a;
}team_t;

int main(void){
  int i, j, n, ans = 0;
  team_t times[MAX];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d %d", &times[i].h, &times[i].a);
  }
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++){
      if(i == j) continue;
      if(times[i].h == times[j].a) ans++;
    }
  printf("%d\n", ans);
  
  return 0;
}
