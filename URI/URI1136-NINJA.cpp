#include <stdio.h>
#include <string.h>

#define MAX 112
#define valido(x) (x) >= 0 && (x) <= n

int main(void){
  int n, b, dif, ans, i, j, balls[MAX], possible[MAX];

  while(scanf("%d %d", &n, &b), n || b){
    memset(possible, 0, sizeof(possible));
    for(ans = i = 0; i < b; i++) scanf("%d", &balls[i]);
    for(i = 0; i < b; i++){
      for(j = 0; j < b; j++){
	dif = balls[i] - balls[j];
	if(valido(dif) && !possible[dif]){
	  possible[dif] = 1;
	  ans++;
	}
      }
    }
    //printf("%d\n", ans);
    printf("%c\n", ans == n+1 ? 'Y' : 'N');
  }

  return 0;
}
