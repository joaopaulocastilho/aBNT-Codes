#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXW 1123
#define MAXC 11

char matrix[][5][7]={
  {".***..", "*...*.", "*****.", "*...*.", "*...*."}, // A
  {"****..", "*...*.", "****..", "*...*.", "****.."}, // B
  {".****.", "*...*.", "*.....", "*.....", ".****."}, // C
  {"****..", "*...*.", "*...*.", "*...*.", "****.."}, // D
  {"*****.", "*.....", "***...", "*.....", "*****."}, // E
  {"*****.", "*.....", "***...", "*.....", "*....."}, // F
  {".****.", "*.....", "*..**.", "*...*.", ".***.."}, // G
  {"*...*.", "*...*.", "*****.", "*...*.", "*...*."}, // H
  {"*****.", "..*...", "..*...", "..*...", "*****."}, // I
  {"..***.", "...*..", "...*..", "*..*..", ".**..."}, // J
  {"*...*.", "*..*..", "***...", "*..*..", "*...*."}, // K
  {"*.....", "*.....", "*.....", "*.....", "*****."}, // L
  {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."}, // M
  {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."}, // N
  {".***..", "*...*.", "*...*.", "*...*.", ".***.."}, // O
  {"****..", "*...*.", "****..", "*.....", "*....."}, // P
  {".***..", "*...*.", "*...*.", "*..**.", ".****."}, // Q
  {"****..", "*...*.", "****..", "*..*..", "*...*."}, // R
  {".****.", "*.....", ".***..", "....*.", "****.."}, // S
  {"*****.", "*.*.*.", "..*...", "..*...", ".***.."}, // T
  {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."}, // U
  {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."}, // V
  {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."}, // W
  {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."}, // X
  {"*...*.", ".*.*..", "..*...", "..*...", "..*..."}, // Y
  {"*****.", "...*..", "..*...", ".*....", "*****."}, // Z
  {"......", "......", "......", "......", "......"} // BLANK;
};
  
char pagina[70][70];

int verifica(int j, int i){
  if(j >= 0 && j < 60 && i >=0 && i <= 60)
    return 1;
  return 0;
}

void imprima_grande(int column, int row, char text[]){
  int len = strlen(text);
  for(int i = 0; i < len ; i++)
    if(text[i] == '|') {
      for(int j = i; j < len; j++) text[j] = text[j+1];
      len--;
    }
  for(int i = 0; i < len; i++){
    for(int j = 0; j < 5; j++){
      for(int k = 0; k < 6; k++){
	if(verifica(row+j, k+column)){
	  if(text[i] == ' ' || matrix[text[i] - 'A'][j][k] == '.' ) continue;
	  else pagina[row+j][k+column] = matrix[text[i] - 'A'][j][k];
	}
      }
    }
    column += 6;
  }
}

void imprima_pagina(){
  //printf("     ");
  //for(int i = 0; i < 60; i++)
  //  printf("%2d", i);
  //printf("\n");
  for(int i = 0; i < 60; i++){
    for(int j = 0; j < 60; j++)
      printf("%c", pagina[i][j]);
    printf("\n");
  }

}

void imprima_pequeno(int column, int row, char text[]){
  int len = strlen(text);
  for(int i = 0; i < len ; i++)
    if(text[i] == '|') {
      for(int j = i; j < len; j++) text[j] = text[j+1];
      len--;
    }
  for(int i = 0; i < len; i++){
    if(verifica(row, column+i) && text[i] != ' ') pagina[row][column+i] = text[i];
  }
}

int main(void){
  int arg2, column, arg3, finnish = 0;
  char arg1[MAXC], command[MAXC], text[MAXW], c;
  for(int i = 0; i < 61; i++) for(int j = 0; j < 61; j++) pagina[i][j] = '.';
  while(!finnish){
    if(scanf("%s", command) == EOF){
      finnish = 1;
      continue;
    }
    if(command[1] == 'E'){
      imprima_pagina();
      printf("\n");
      for(int i = 0; i < 60; i++) printf("-");
      printf("\n\n");
      for(int i = 0; i < 61; i++) for(int j = 0; j < 61; j++) pagina[i][j] = '.';
      continue;
    }
    scanf("%s", arg1);
    scanf("%d", &arg2);
    if(command[1] == 'P') scanf("%d", &arg3);
    while(c = getchar(), c != '|');
    fgets(text, MAXW, stdin);
    text[strlen(text)-1] = '\0';
    if(command[1] == 'C'){
      if(arg1[1] == '5'){
	//printf("%d %s\n", strlen(text), text);
	column = (30 - ((strlen(text)-1)*6)/2);
	imprima_grande(column, arg2-1, text);
      }
      else{
	column = (30 - (strlen(text)-1)/2);
	imprima_pequeno(column, arg2-1, text);
      }
    }
    else if(command[1] == 'P'){
      if(arg1[1] == '5') imprima_grande(arg3-1, arg2-1, text);
      else imprima_pequeno(arg3-1, arg2-1, text);
    }
    else if(command[1] == 'L'){
      if(arg1[1] == '5') imprima_grande(0, arg2-1, text);
      else imprima_pequeno(0, arg2-1, text);
    }
    else if(command[1] == 'R'){
      if(arg1[1] == '5'){
	column = (60 - ((strlen(text)-1)*6));
	imprima_grande(column, arg2-1, text);
      }
      else{
	column = (60 - ((strlen(text)-1)));
	imprima_pequeno(column, arg2-1, text);
      }
    }
  }
  return 0;
}
