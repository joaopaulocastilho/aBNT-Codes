#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 31

typedef struct{
  int time, pizza;
}order_t;

int n, p,  memo[MAX][MAX];
order_t orders[MAX];

int pd(int i, int qtd){
  if(i >= n) return 0;
  if(memo[i][qtd] != -1) return memo[i][qtd];
  if(qtd + orders[i].pizza > p) return memo[i][qtd] = pd(i + 1, qtd);
  return memo[i][qtd] = max(pd(i + 1, qtd), pd(i + 1, qtd + orders[i].pizza) + orders[i].time);
}

int main(void){
  int i;
  
  while(scanf("%d %d", &n, &p), n){
    memset(memo, -1, sizeof(memo));
    for(i = 0; i < n; i++)
      scanf("%d %d", &orders[i].time, &orders[i].pizza); 
    printf("%d min.\n", pd(0, 0));
  }

  return 0;
}
