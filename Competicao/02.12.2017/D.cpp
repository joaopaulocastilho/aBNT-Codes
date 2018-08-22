#include <cstdio>

int main(void){
  int n, i, idx = 0, maior = -1, segmaior = -1, preco;
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &preco);
    if(preco > maior){
      segmaior = maior;
      maior = preco;
      idx = i;
      continue;
    }
    if(preco > segmaior) segmaior = preco;
  }
  printf("%d %d\n", idx, segmaior);
}
