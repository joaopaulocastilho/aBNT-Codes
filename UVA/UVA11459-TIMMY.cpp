#include <cstdio>
#include <cstring>

#define MAXS 112
#define MAXP 1123456
int main(void){
  int vec[MAXS], players[MAXP], turn, roll, start, end, p, s, r, tc;

  scanf("%d", &tc);
  while(tc--){
    turn = 0;
    memset(vec, 0, sizeof(vec));
    memset(players, 0, sizeof(players));
    scanf("%d %d %d", &p, &s, &r);
    while(s--){
      scanf("%d %d", &start, &end);
      vec[--start] = --end;
    }
    while(r--){
      scanf("%d", &roll);
      players[turn] += roll;
      if(players[turn] < 99 && vec[players[turn]] != 0) players[turn] = vec[players[turn]];
      if(players[turn] >= 99){
	players[turn] = 99;
	while(r--){ scanf("%d", &roll); }
	break;
      }	
      turn = (turn + 1) % p;
    }
    for(int i = 0; i < p; i++){
      printf("Position of player %d is %d.\n", i+1, players[i]+1);
    }
  }
  return 0;
}
  
