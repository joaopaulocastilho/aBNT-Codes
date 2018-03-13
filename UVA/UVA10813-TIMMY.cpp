#include <cstdio>
#include <cstring>

//define DEBUG
#define MAX 6

int main(void){
  int tc, matrix[MAX][MAX], num, row, ans[MAX][MAX], count, winner, win, line, found;
  scanf("%d", &tc);
  while(tc--){
    memset(ans, 0, sizeof(ans));
    matrix[2][2] = -1;
    ans[2][2] = 1;
    count = 0;
    winner = 0;
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
	if(i == 2 && j == 2) continue;
	scanf("%d", &num);
	matrix[i][j] = num;
      }
    }
    while(!winner){
      scanf("%d", &num);
      count++;
      found = 0;
      if(num > 0 && num < 16) row = 0;
      else if(num > 15 && num < 31) row = 1;
      else if(num > 30 && num < 46) row = 2;
      else if(num > 45 && num < 61) row = 3;
      else row = 4;
      for(int i = 0; i < 5; i++){
	if(matrix[i][row] == num){ ans[i][row] = 1; line = i; found = 1; }
      }
      if(found){
	win = 1;
	for(int j = 0; j < 5; j++){ if(ans[j][j] == 0) win = 0; }
	if(win){
	  printf("BINGO after %d numbers announced\n", count);
	  for(int i = count; i < 75; i++) scanf("%d", &num);
	  winner = 1;
	  continue;
	}
	win = 1;
	for(int i = 0; i < 5; i++) if(ans[i][row] == 0) win = 0;
	if(win){
	  printf("BINGO after %d numbers announced\n", count);
	  for(int i = count; i < 75; i++) scanf("%d", &num);
	  winner = 1;
	  continue;
	}
	win = 1;
	for(int i = 0; i < 5; i++) if(ans[line][i] == 0) win = 0;
	if(win){
	  printf("BINGO after %d numbers announced\n", count);
	  for(int i = count; i < 75; i++) scanf("%d", &num);
	  winner = 1;
	  continue;
	}
	win = 1;
	for(int i = 0, j = 4; i < 5 && j >= 0; i++, j--) if(ans[i][j] == 0) win = 0;
	if(win){
	  printf("BINGO after %d numbers announced\n", count);
	  for(int i = count; i < 75; i++) scanf("%d", &num);
	  winner = 1;
	  continue;
	}
      }
    }
  }
  return 0;
}
