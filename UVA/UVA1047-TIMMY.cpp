#include <cstdio>
#include <cstring>

#define MAX 112

int v[MAX];

int aumenta_valor(int towers, int m){
  int i, j, k, l;
  for(i = m-1, j = 0; i >= 0; i--, j++)
    if(v[i]+1 <= towers - j){
      v[i]++;
      break;
    }
  if(i < 0) return 0;
  for(k = i+1, l = 1; k < m; k++, l++){
    v[k] = v[i] + l;
  }
  return 1;
}


int main(void){
  int towers, m, i, tower[MAX], ni, tpart[MAX][MAX], qtdt[MAX], num[MAX], ans, localans, used[MAX], j, l, vans[MAX], caso = 1;
  while(scanf("%d %d", &towers, &m) && towers + m != 0){
    for(i = 1; i <= towers; i++) scanf("%d", &tower[i]);
    scanf("%d", &ni);
    for(i = 1; i <= ni; i++){
      scanf("%d", &qtdt[i]);
      for(int j = 1; j <= qtdt[i]; j++) scanf("%d", &tpart[i][j]);
      scanf("%d", &num[i]);
      for(int j = 1; j <= qtdt[i]; j++) tower[tpart[i][j]] -= num[i];
    }
    for(i = 0; i < m; i++) v[i] = i+1;
    ans = 0;
    while(1){
      localans = 0;
      memset(used, 0, sizeof(used));
      for(i = 0; i < m; i++)
	localans += tower[v[i]];
      for(i = 1; i <= ni; i++)
	for(j = 1; j <= qtdt[i] && !used[i]; j++)
	  for(l = 0; l < m && !used[i]; l++){
	    if(tpart[i][j] == v[l] && !used[i]){ localans+= num[i]; used[i] = 1; }
	  }
      if(localans > ans){
	ans = localans;
	for(i = 0; i < m; i++) vans[i] = v[i];
      }
      if(aumenta_valor(towers, m) == 0) break;
    }
    printf("Case Number  %d\n", caso++);
    printf("Number of Customers: %d\n", ans);
    printf("Locations recommended:");
    for(i = 0; i < m; i++) printf(" %d", vans[i]);
    printf("\n\n");
  }
  return 0;
}
