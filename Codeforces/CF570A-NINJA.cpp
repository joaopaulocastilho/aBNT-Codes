#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, n, m, voto, city[MAX], cities[MAX], big, bigin;

  scanf("%d %d", &n, &m);
  memset(cities, 0, sizeof(cities));
  for(i = 0; i < m; i++){
    memset(city, 0, sizeof(city));
    for(j = 1; j <= n; j++){
      scanf("%d", &voto);
      city[j] += voto;
    }
    for(big = bigin = -1, j = 1; j <= n; j++){
      if(city[j] > big){
	big = city[j];
	bigin = j;
      }
    }
    //printf("%d\n", bigin);
    cities[bigin]++;
  }
  for(big = bigin = -1, i = 1; i <= n; i++){
    if(cities[i] > big){
      big = cities[i];
      bigin = i;
    }
  }
  printf("%d\n", bigin);
  
  return 0;
}
