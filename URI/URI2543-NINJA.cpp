#include <stdio.h>

int main(void){
  int n, i, resp , num, game;

  while(scanf("%d %d", &n, &i) != EOF){
    resp = 0;
    while(n--){
      scanf("%d %d", &num, &game);
      if(num == i && game == 0) resp++;
    }
    printf("%d\n", resp);
  }
  return 0;
}
