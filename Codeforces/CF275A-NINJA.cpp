#include <stdio.h>

#define valido(i, j) (i) < 3 && (i) >= 0 && (j) < 3 && (j) >= 0

int posi[5] = {0, 0, 1, 0, -1};
int posj[5] = {0, -1, 0, 1, 0};

int main(void){
  int i, j, k, ni, nj, num, m[3][3];

  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) m[i][j] = 1;
  
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++){ 
      scanf("%d", &num);
      if(num % 2){
	for(k = 0; k < 5; k++){
	  ni = i + posi[k]; nj = j + posj[k];
	  if(valido(ni, nj)) m[ni][nj] = m[ni][nj] == 1 ? 0 : 1; 
	}
      }
    }
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++) printf("%d", m[i][j]);
    printf("\n");
  }
  return 0;
}
