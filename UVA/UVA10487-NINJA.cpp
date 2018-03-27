#include <stdio.h>
#include <stdlib.h>

#define MAX 1123
#define INF 112345678

int main(void){
  int i, j, ans, menor, q, n, caso = 1, targ, nums[MAX];

  while(scanf("%d", &n), n){
    for(i = 0; i < n; i++) scanf("%d", &nums[i]);
    scanf("%d", &q);
    printf("Case %d:\n", caso++);
    while(q--){
      scanf("%d", &targ);
      for(menor = INF, i = 0; i < n; i++)
	for(j = 0; j < n; j++){
	  if(i == j) continue;
	  if(abs((nums[i] + nums[j]) - targ) < menor){
	    menor = abs((nums[i] + nums[j]) - targ);
	    ans = nums[i] + nums[j];
	  }
	}
      printf("Closest sum to %d is %d.\n", targ, ans);
    }
  }

  return 0;
}
