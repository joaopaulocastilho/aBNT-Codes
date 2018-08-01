#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX1 3123
#define MAX2 1123456

int main(void){
  int i, n, rema, diff, seq[MAX1], dig[MAX2];

  while(scanf("%d", &n) != EOF){
    memset(dig, 0, sizeof(dig));
    for(rema = n-1, i = 0; i < n; i++) scanf("%d", &seq[i]);
    for(i = 1; i < n; i++){
      diff = abs(seq[i]-seq[i-1]);
      if(diff >= 1 && diff < n && !dig[diff]){ dig[diff] = 1; rema--; }
    }
    if(rema) printf("Not jolly\n");
    else printf("Jolly\n");
  }
  
  return 0;
}
