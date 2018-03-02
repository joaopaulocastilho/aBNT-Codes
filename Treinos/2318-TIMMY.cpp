#include <cstdio>

int main(void){
  int i, j, soma, flag, matrix[3][3], sominha;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++){
      scanf("%d", &matrix[i][j]);
    }
  flag = 0;
  for(i = 0; i < 3; i++)
    if(matrix[i][i] == 0) flag = 1;
  if(flag){
    flag = 0;
    for(i = 2, j = 0; i >= 0; i--, j++)
      if(matrix[i][j] == 0) flag = 1;
    if(flag){
      flag = 0;
      for(i = 0; i < 3; i++){
	for(j = 0; j < 3; j++)
	  if(matrix[i][j] == 0) flag = 1;
	if(!flag) break;
      }
      if(flag){
	flag = 0;
	for(j = 0; j < 3; j++){
	  for(i = 0; i < 3; i++)
	    if(matrix[i][j] == 0) flag = 1;
	  if(!flag) break;
	}
	//printf("Quarto Caso\n");
	soma = 0;
	for(i = 0; i < 3; i++)
	  soma += matrix[i][j];
      }
      else{
	//printf("Terceiro Caso\n");
	soma = 0;
	for(j = 0; j < 3; j++)
	  soma+= matrix[i][j];
      }
    }
    else{
      //printf("Segundo Caso\n");
      soma = 0;
      for(i = 2, j = 0; i >= 0; i--, j++)
	soma += matrix[i][j];
    }
  }
  else{
    //printf("Primeiro Caso\n");
    soma = 0;
    for(i = 0; i < 3; i++)
      soma += matrix[i][i];
  }
  for(i = 0; i < 3; i++){
    sominha = 0;
    for(j = 0; j < 3; j++) sominha += matrix[i][j];
    for(j = 0; j < 3; j++) if(matrix[i][j] == 0) matrix[i][j] = soma - sominha;
  }
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
  return 0;
}
