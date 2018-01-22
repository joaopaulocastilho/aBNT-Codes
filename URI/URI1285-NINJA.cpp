#include <stdio.h>
#include <string.h>

int difDig(int x){
  int dig[10];

  memset(dig, 0, sizeof(dig));
  for( ; x; x /= 10){
    if(dig[x%10]) return 0;
    dig[x%10] = 1;
  }
  return 1;
}

int main(void){
  int ans, n, m, i;
  
  while(scanf("%d %d", &n, &m) != EOF){
    for(ans = 0, i = n; i <= m; i++)
      if(difDig(i)) ans++;
    printf("%d\n", ans); 
  }

  return 0;
}
