#include <stdio.h>

int main(void){
  int n, tmp, sim;

  while(scanf("%d", &n) != EOF){
    for(int i = sim = 0; i < n; i++){
      scanf("%d", &tmp);
      if(tmp) sim++;
    }
    if(sim >= (2 * (double) n) / 3) printf("impeachment\n");
    else printf("acusacao arquivada\n");
  }

  return 0;
}
