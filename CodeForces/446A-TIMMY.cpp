#include <cstdio>

#define ll long long int

int main(void){
  int n, resto, capacidade, maior1 = 0, maior2 = 0, i;
  ll ans;
  scanf("%d", &n);
  if(n == 2) printf("YES\n");
  else{
    for(i = 0; i < n; i++){
      scanf("%d", &resto);
      ans += resto;
    }
    for(i = 0; i < n; i++){
      scanf("%d", &capacidade);
      if(capacidade > maior1){
	maior2 = maior1;
	maior1 = capacidade;
      }
      else if(capacidade > maior2)
	maior2 = capacidade;
    }
    if(ans <= maior1 + maior2) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
