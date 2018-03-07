#include <stdio.h>

#define MAX 112

int main(void){
  int i, n, k, part[MAX], ans = 0;
  
  scanf("%d %d", &n, &k);
  for(i = 1; i <= n; i++) scanf("%d", &part[i]);
  for(i = k; part[i] == part[k]; i++);
  for(i--; i > 0; i--) if(part[i] > 0) ans++;
  printf("%d\n", ans);
  return 0;
}
