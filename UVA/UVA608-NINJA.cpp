#include <stdio.h>
#include <string.h>

#define MAX 212

int main(void){
  int i, j, k, n, even, up, down, end, found;
  char coins[MAX], str1[MAX], str2[MAX], res[MAX];

  scanf("%d ", &n);
  while(n--){
    memset(coins, 0, sizeof(coins));
    for(i = 0; i < 3; i++){
      scanf("%s %s %s ", str1, str2, res);
      even = !strcmp(res, "even");
      down = !strcmp(res, "down");
      up = !(down || even);
      //printf("%d %d %d\n", even, up, down);
      end = strlen(str1);
      for(j = 'A'; j <= 'L'; j++){
	if(coins[j] == 'T') continue;
	for(found = 0, k = 0; k < end; k++){
	  if(j == str1[k]){
	    found = 1;
	    if(even) coins[j] = 'T';
	    else if(coins[j] != 0){
	      if(coins[j] == 'H') coins[j] = down ? 'T' : 'H';
	      else coins[j] = up ? 'T' : 'L';
	    }
	    else coins[j] = down ? 'L' : 'H';
	  }
	  else if(j == str2[k]){
	    found = 1;
	    if(even) coins[j] = 'T';
	    else if(coins[j] != 0){
	      if(coins[j] == 'H') coins[j] = down ? 'H' : 'T';
	      else coins[j] = up ? 'L' : 'T';
	    }
	    else coins[j] = down ? 'H' : 'L';
	  }
	}
	if(!found && !even) coins[j] = 'T';
      }
      //for(int z = 'A'; z <= 'L'; z++) printf("%c ", coins[z] == 0 ? '0' : coins[z]); printf("\n");
    }
    for(i = 'A'; i <= 'L'; i++){
      if(coins[i] == 'H' || coins[i] == 'L')
	printf("%c is the counterfeit coin and it is %s.\n", i, coins[i] == 'H' ? "heavy" : "light");
      //printf("%c\n", coins[i] == 0 ? '0' : coins[i]);
    }
  }

  return 0;
}
