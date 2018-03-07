#include <stdio.h>
#include <string.h>

#define MAX 1123456
#define MAX2 112

int main(void){
  int i, t, players, ended, snadders, num, rolls, u, v, turn = 1, pos[MAX], ways[MAX2];
  
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d", &players, &snadders, &rolls);
    memset(ways, -1, sizeof(ways)); 
    for(i = 1; i <= players; i++) pos[i] = 1;
    while(snadders--){
      scanf("%d %d", &u, &v);
      ways[u] = v;
    }
    for(ended = i = 0; i < rolls; i++, turn = turn == players ? 1 : turn + 1){
      scanf("%d", &num);
      if(ended) continue;
      pos[turn] += num;
      if(ways[pos[turn]] != -1) pos[turn] = ways[pos[turn]];
      if(pos[turn] >= 100) ended = 1;
    }
    for(i = 1; i <= players; i++) printf("Position of player %d is %d.\n", i, pos[i] > 100 ? 100 : pos[i]);
  }
  
  return 0;
}
