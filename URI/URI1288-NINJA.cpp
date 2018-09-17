#include <bits/stdc++.h>

using namespace std;

typedef struct{
  int dano, peso;
}tiro_t;

const int MAX = 112;

int n, r, k, memo[MAX][MAX];
tiro_t balas[MAX];

int pd(int i, int w){
  if(i == n) return 0;
  if(memo[i][w] != -1) return memo[i][w];
  if(w + balas[i].peso > k) return memo[i][w] = pd(i+1, w);
  else return memo[i][w] = max(pd(i+1, w+balas[i].peso)+balas[i].dano, pd(i+1, w));
}

int main(void){
  int i, t;
  
  scanf("%d", &t);
  while(t--){
    memset(memo, -1, sizeof(memo));
    scanf("%d", &n);
    for(i = 0; i < n; i++)
      scanf("%d %d", &balas[i].dano, &balas[i].peso);
    scanf("%d", &k);
    scanf("%d", &r);
    if(pd(0, 0) >= r) printf("Missao completada com sucesso\n");
    else printf("Falha na missao\n");
  }
  return 0;
}
