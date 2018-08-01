#include <stdio.h>
#include <string.h>

#define MAX 1123

char tmp[MAX][MAX], big[MAX][MAX], small[MAX][MAX];

int main(void){
  int i, j, k, l, o, p, n, m, flag, ans[4];

  while(scanf("%d %d ", &n, &m), n){
    memset(ans, 0, sizeof(ans));
    for(i = 0; i < n; i++) scanf("%s ", big[i]);
      for(i = 0; i < m; i++) scanf("%s ", small[i]);
    
    for(p = 0; p < 4; p++){
      //for(i = 0; i < m; i++) printf("%s\n", small[i]);printf("\n");

      for(i = 0; i <= n-m; i++)
	for(j = 0; j <= n-m; j++){
	  for(flag = 1, l = 0; l + i < i + m; l++)
	    for(o = 0; o + j < j + m; o++){
	      //printf("Comparando %c e %c\n", big[i+l][j+o], small[l][o]); 
	      if(big[i+l][j+o] != small[l][o]) flag = 0;
	    }
	  //printf("\n");
	  if(flag) ans[p]++;
	}
      
      for(i = 0; i < m; i++)
	for(j = 0; j < m; j++) tmp[i][j] = small[i][j];

      for(k = m-1, i = 0; i < m; i++, k--)
	for(j = 0; j < m; j++)
	  small[j][k] = tmp[i][j];
    }
    for(i = 0; i < 4; i++) printf("%s%d", i ? " " : "", ans[i]);
    printf("\n");
  }
  return 0;
}
