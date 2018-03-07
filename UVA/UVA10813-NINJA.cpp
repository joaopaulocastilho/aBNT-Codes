#include <stdio.h>

int main(void){
  int i, j, k, l, n, count, num, flag, ans, card[5][5];
  scanf("%d", &n);
  while(n--){
    ans = -1;
    for(i = 0; i < 5; i++)
      for(j = 0; j < 5; j++){
	if(i == j && j == 2){card[i][j] = -1; continue;}
	scanf("%d", &card[i][j]);
      }
    for(count = 1; count <= 75; count++){
      scanf("%d", &num);
      for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++){
	  if(card[i][j] == num){
	    card[i][j] = -1;
	    for(flag = 1, k = 0; k < 5; k++)
	      if(card[i][k] != -1) flag = 0;
	    if(flag && ans == -1) ans = count;

	    for(flag = 1, k = 0; k < 5; k++)
	      if(card[k][j] != -1) flag = 0;
	    if(flag && ans == -1) ans = count;

	    if(i == j){
	      for(flag = 1, k = l = 0; k < 5; k++, l++)
		if(card[k][l] != -1) flag = 0;
	      if(flag && ans == -1) ans = count;
	    }

	    for(flag = 1, k = 0, l = 4; l >= 0; k++, l--)
	      if(card[k][l] != -1) flag = 0;
	    if(flag && ans == -1) ans = count;
	  }
	}
    }
    printf("BINGO after %d numbers announced\n", ans);
  }
  return 0;
}
