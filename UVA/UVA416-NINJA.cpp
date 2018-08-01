#include <stdio.h>
#include <string.h>

#define MAX 15

char decode[MAX][MAX] = {{"1111110"},
			 {"0110000"},
			 {"1101101"},
			 {"1111001"},
			 {"0110011"},
			 {"1011011"},
			 {"1011111"},
			 {"1110000"},
			 {"1111111"},
			 {"1111011"}
};

int n, ans, currNum, flag;
char numbers[MAX][MAX], currStr[MAX], tmp[MAX];

int acendeu(int x, int j){
  int i;
  for(i = x; i < n; i++) if(numbers[i][j] == '1') return 1;
  return 0;
}


void bt(int i, int currNum, char currStr[]){
  int j, k;
  //printf("%d %d %d %s -> %s\n", currNum, i, n, currStr, numbers[i+1]);
  if(i == n-1) {ans = 1; return;}
  if(currNum == 0) return;
  strcpy(currStr, numbers[i+1]);
  //printf("%s ---> %s\n", numbers[i+1], decode[currNum-1]);
  for(k = 0; k < 7; k++)
    if((numbers[i+1][k] == '1' && decode[currNum-1][k] == '0') || (acendeu(i+1, k) && numbers[i+1][k] == '0' && decode[currNum-1][k] == '1')) return;
  bt(i+1, currNum-1, currStr);
}

int main(void){
  int i, j;
  char str[MAX];

  while(scanf("%d", &n), n){
    for(ans = i = 0; i < n; i++) {
      scanf("%s ", numbers[i]);
      for(j = 0; j < 7; j++)
	numbers[i][j] = numbers[i][j] == 'Y' ? '1' : '0';
    }
    for(i = 0; i < 10; i++){
      for(flag = 1, j = 0; j < 7; j++){
	if((numbers[0][j] == '1' && decode[i][j] == '0') || (acendeu(1, j) && numbers[0][j] == '0' && decode[i][j] == '1')) {flag = 0; break;}
       }
	if(flag){
	strcpy(currStr, numbers[0]);
	bt(0, i, currStr);
      }
    }
    printf("%sMATCH\n", ans ? "" : "MIS");
  }
  return 0;
}
