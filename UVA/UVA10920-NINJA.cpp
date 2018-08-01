#include <stdio.h>

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

typedef long long ll;

int main(void){
  int dir, desl, i, j, sz, tc;
  ll p, k;
  
  while(scanf("%d %lld", &sz, &p), sz){
    for(tc = 0, dir = UP, desl = k = 1, i = j = sz/2+1; k != p;){
      //printf("%d,%d d:%d k:%lld tc:%d, dir:%d\n", i, j, desl, k, tc, dir);
      if(k + desl <= p){
	k += desl;
	if(dir == UP) i += desl;
	else if(dir == LEFT) j -= desl;
	else if(dir == DOWN) i -= desl;
	else if(dir == RIGHT) j += desl;
	if(dir == UP) dir = LEFT;
	else if(dir == LEFT) dir = DOWN;
	else if(dir == DOWN) dir = RIGHT;
	else if(dir == RIGHT) dir = UP;
	if(tc == 1){ tc = 0; desl++; }
	else tc++;
      }
      else
	while(k != p){
	  k++;
	  if(dir == UP) i++;
	  else if(dir == LEFT) j--;
	  else if(dir == DOWN) i--;
	  else if(dir == RIGHT) j++;
	}
    }
    printf("Line = %d, column = %d.\n", i, j);
  }

  return 0;
}
