#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 31
#define INF 1123456

typedef struct{
  int tempo;
  int qtd;
} pz;

pz pizza[MAX];
int lim, tc;
int memo[MAX][MAX];

int pd(int i, int qtd){
  if(i == tc) return 0;
  if(memo[i][qtd] != -1) return memo[i][qtd];
  if(qtd + pizza[i].qtd > lim) return memo[i][qtd] = pd(i+1, qtd);
  return memo[i][qtd] = 
    max(pd(i+1, qtd + pizza[i].qtd) + pizza[i].tempo, pd(i+1, qtd));

}

int main(void){
  while(scanf("%d", &tc), tc != 0){
    memset(memo, -1, sizeof(memo));
    scanf("%d", &lim);
    for(int i = 0; i < tc; i++){
      scanf("%d %d", &pizza[i].tempo, &pizza[i].qtd);
    }
    printf("%d min.\n", pd(0, 0));
  }
  return 0;
}
