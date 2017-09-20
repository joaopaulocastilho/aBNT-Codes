#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

ull quadrado(ull num){
  return num*num;
}

int digitos(ull num){
  int digito = 0;
  if(!num) return 1;
  while(num != 0){
    digito++;
    num /= 10;
  }
  return digito;
}

int main(void){
  int n, i, j, ordem, exc=4, coluna[30], espacos;
  ull m[30][30], num;
  int flag;
  scanf("%d", &n);
  while(n--){
    memset(coluna, 0, sizeof(coluna));
    scanf("%d", &ordem);
    for(i=0; i<ordem; i++)
      for(j=0; j<ordem; j++){
	scanf("%llu", &num);
	m[i][j] = quadrado(num);
	if(coluna[j] < digitos(m[i][j])) coluna[j] = digitos(m[i][j]); 
      }
    printf("Quadrado da matriz #%d:\n", exc);
    exc++;
    for(i=0; i<ordem; i++){
      for(j=0; j<ordem; j++){
	espacos = coluna[j] - digitos(m[i][j]);
	while(espacos--) printf(" ");
	if(j+1 == ordem) flag = 1;
	if(flag){ 
	  printf("%llu", m[i][j]);
	  flag = 0;
	}else printf("%llu ", m[i][j]);
      }
      printf("\n");
    }
    if(n) printf("\n");
  }
  return 0;
}
