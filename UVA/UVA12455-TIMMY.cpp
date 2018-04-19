#include <cstdio>
#include <cstring>


#define MAX 112345

int main(void){
  int v[MAX], auxv[MAX], num, bars, bar, tc;
  
  scanf("%d", &tc);
  while(tc--){
    memset(v, 0, sizeof(v));
    memset(auxv, 0, sizeof(auxv));
    v[0] = 1;
    scanf("%d %d", &num, &bars);
    for(int i = 0; i < bars; i++){
      scanf("%d", &bar);
      auxv[bar] = 1;
      for(int j = 1; j <= num; j++){
	if(v[j] == 1) auxv[j+bar] = 1;
      }
      for(int j = 0; j <= num; j++){
	if(auxv[j] == 1) v[j] = 1;
      }
    }
    if(v[num] == 1) printf("YES\n"); else printf("NO\n");
  }

  return 0;
}
