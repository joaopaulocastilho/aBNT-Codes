#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, n, m, score[MAX][MAX], solved[MAX], solve[MAX], ans, flag, sall;

  while(scanf("%d %d", &n, &m), n || m){
    memset(solved, 0, sizeof(solved));
    memset(solve, 0, sizeof(solve));
    ans = 4;
    for(sall = i = 0; i < n; i++){
      for(flag = 1, j = 0; j < m; j++){
	scanf("%d", &score[i][j]);
	if(!score[i][j]) flag = 0;
	else solve[i] = solved[j] = 1;
      }
      if(flag) sall = 1;
    }
    if(sall) ans--;
    for(i = 0; i < n; i++) if(!solve[i]) { ans--; break; }  
    for(i = 0; i < m; i++) if(!solved[i]) { ans--; break; }

    for(j = 0; j < m; j++){
      for(flag = i = 0; i < n; i++){
	if(!score[i][j]) {flag = 1; break;}
      }
      if(!flag) { ans--; break; }
    }
    printf("%d\n", ans);
  }

  return 0;
}
