#include <stdio.h>

#define MAX 112

int r, c;
char tab1[MAX][MAX], tab2[MAX][MAX];

char RockPaperScissor(char a, char b){
  if(a == 'R' && b == 'P' || a == 'P' && b == 'R') return 'P';
  if(a == 'P' && b == 'S' || a == 'S' && b == 'P') return 'S';
  if(a == 'R' && b == 'S' || a == 'S' && b == 'R') return 'R';
  return 'D';
}

void copyTabs(char tab1[MAX][MAX], char tab2[MAX][MAX]){
  int i, j;
  for(i = 0; i < r; i++)
    for(j = 0; j < c; j++)
      tab1[i][j] = tab2[i][j];
}

void printTab(){
  int i, j;
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++)
      printf("%c", tab1[i][j]);
    printf("\n");
  }
}

int main(void){
  int i, j, k, t, d, first = 1;
  char result;
  
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d ", &r, &c, &d);
    for(i = 0; i < r; i++) scanf("%s", tab1[i]);
    copyTabs(tab2, tab1);
    //printTab(); printf("\n");
    for(k = 0; k < d; k++){
      for(i = 0; i < r; i++){
	for(j = 0; j < c; j++){
	  if(j != c-1){
	    result = RockPaperScissor(tab1[i][j], tab1[i][j+1]);
	    //printf("Checking (%d, %d)(%c) -> (%d, %d)(%c), result: %c", i, j, tab1[i][j], i, j+1, tab1[i][j+1], result);  
	    if(result == tab1[i][j]) tab2[i][j+1] = tab1[i][j];
	    else if(result != 'D') tab2[i][j] = tab1[i][j+1];
	  }
	  if(i != r-1){
	    result = RockPaperScissor(tab1[i][j], tab1[i+1][j]); 
	    //printf(" and (%d, %d)(%c) -> (%d, %d)(%c), result: %c", i, j, tab1[i][j], i+1, j, tab1[i+1][j], result); 
	    if(result == tab1[i][j]) tab2[i+1][j] = tab1[i][j];
	    else if(result != 'D') tab2[i][j] = tab1[i+1][j]; 
	  }
	  //printf("\n");
	}
      }
      copyTabs(tab1, tab2);
      //printTab(); printf("\n");
    }
    if(first) first = 0;
    else printf("\n");
    printTab();
  }
  return 0;
}
