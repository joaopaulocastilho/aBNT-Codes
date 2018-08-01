#include <stdio.h>
#include <string.h>

#define MAX 112

char keyb[][11] = {{"qwertyuiop"},
		 {"asdfghjkl;"},
		 {"zxcvbnm,./"}};

int main(void){
  char seq[MAX], dir;
  int end, i, j, k;
  
  scanf("%c ", &dir);
  scanf("%s ", seq);

  for(end = strlen(seq), k = 0; k < end; k++)
    for(i = 0; i < 3; i++)
      for(j = 0; j < 10; j++)
	if(keyb[i][j] == seq[k])
	  printf("%c", dir == 'R' ? keyb[i][j-1] : keyb[i][j+1]);
  printf("\n");
  
  return 0;
}
