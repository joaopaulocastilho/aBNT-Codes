#include <stdio.h>

#define MAXT 31
#define INF 123456789

typedef struct{
  int qtd, val, towers[MAXT];
}intersec_t;

int n, b;

int nextComb(int *currPerm){
  int i, lim, incr = 0;
  
  for(lim = n, i = b-1; i >= 0; i--, lim--)
    if(currPerm[i] < lim){ currPerm[i]++; incr = 1; break; }
  if(incr) for(i = i+1; i < b; i++) currPerm[i] = currPerm[i-1] + 1;

  return incr;
}

int main(void){
  int i, j, k, m, flag, reach[MAXT], currPerm[MAXT], ansTowers[MAXT], ansCurr, ansMax, caso = 1;
  intersec_t inter[MAXT];
  
  while(scanf("%d %d", &n, &b), n){
    for(i = 1; i <= n; i++) scanf("%d", &reach[i]);
    scanf("%d", &m);
    for(i = 0; i < m; i++){
      scanf("%d", &inter[i].qtd);
      for(j = 0; j < inter[i].qtd; j++) scanf("%d", &inter[i].towers[j]);
      scanf("%d", &inter[i].val);
    }
    for(i = 0; i < m; i++)
      for(j = 0; j < inter[i].qtd; j++)
	reach[inter[i].towers[j]] -= inter[i].val;

    //for(i = 1; i <= n; i++) printf("%d ", reach[i]); printf("\n");

    for(ansMax = -INF, i = 0; i < b; i++) ansTowers[i] = currPerm[i] = i+1;
    do{
      //for(i = 0; i < b; i++) printf("%d ", currPerm[i]); printf("\n");
      for(ansCurr = i = 0; i < b; i++) ansCurr += reach[currPerm[i]];
      for(i = 0; i < m; i++)
	for(flag = j = 0; j < inter[i].qtd && !flag; j++)
	  for(k = 0; k < b; k++)
	    if(currPerm[k] == inter[i].towers[j]){ansCurr += inter[i].val; flag = 1;}
      if(ansCurr > ansMax){
	ansMax = ansCurr;
	for(i = 0; i < b; i++) ansTowers[i] = currPerm[i];
      }
      //printf("%d\n", ansCurr);
    }while(nextComb(currPerm));
    printf("Case Number  %d\n", caso++);
    printf("Number of Customers: %d\n", ansMax);
    printf("Locations recommended:");
    for(i = 0; i < b; i++) printf(" %d", ansTowers[i]);
    printf("\n\n");
  }

  return 0;
}
