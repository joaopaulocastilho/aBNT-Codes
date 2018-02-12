#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, p, atual, ant, flag, i;
  scanf("%d %d %d", &p, &n, &ant);
  for (flag = i = 1; flag && i < n; i++) {
    scanf("%d", &atual);
    if (abs(atual - ant) > p) flag = 0; 
    ant = atual;
  }
  printf("%s\n", flag ? "YOU WIN" : "GAME OVER");
  return 0;
}
