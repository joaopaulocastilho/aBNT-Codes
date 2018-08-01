#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, n, c, m, fig, carimb[MAX], bought[MAX], ans;

  
  memset(carimb, 0, sizeof(carimb));
  memset(bought, 0, sizeof(bought));
  scanf("%d %d %d", &n, &c, &m);
  for(i = 0; i < c; i++){
    scanf("%d", &fig);
    carimb[fig] = 1;
  }
  for(ans = c, i = 0; i < m; i++){
    scanf("%d", &fig);
    if(!bought[fig] && carimb[fig]) ans--;
    bought[fig] = 1;
  }
  printf("%d\n", ans);
  
  return 0;
}
