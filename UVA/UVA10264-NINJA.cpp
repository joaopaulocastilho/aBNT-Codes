#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 41234

int pou(int x, int n){
  int i, ans;
  for(ans = 1, i = 0; i < n; i++)
    ans *= x;
  return ans;
}

int main(void){
  int ans, fim, curr, n, weight[MAX], pot[MAX], i, j;

  while(scanf("%d", &n) != EOF){
    fim = pou(2, n);
    for(i = 0; i < fim; i++) scanf("%d", &weight[i]);
    for(i = 0; i < fim; i++){
      for(pot[i] = j = 0; j < n; j++)
	pot[i] += weight[i ^ (1 << j)];
      //printf("->%d\n", pot[i]);
    }
    for(ans = i = 0; i < fim; i++)
      for(curr = j = 0; j < n; j++)
	ans = max(ans, pot[i] + pot[i ^ (1 << j)]);
    printf("%d\n", ans);
  }

  return 0;
}
