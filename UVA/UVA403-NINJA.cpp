#include <stdio.h>
#include <string.h>

#define MAX1 12
#define MAX2 112
#define MAX3 150
#define PAGEL 60
#define valido(r, c) (r < 60 && r >= 0 && c < 60 && c >= 0)

char alfa[][6][7] = {
  {".***..", "*...*.", "*****.", "*...*.", "*...*."}, //A
  {"****..", "*...*.", "****..", "*...*.", "****.."}, //B
  {".****.", "*...*.", "*.....", "*.....", ".****."}, //C
  {"****..", "*...*.", "*...*.", "*...*.", "****.."}, //D
  {"*****.", "*.....", "***...", "*.....", "*****."}, //E
  {"*****.", "*.....", "***...", "*.....", "*....."}, //F
  {".****.", "*.....", "*..**.", "*...*.", ".***.."}, //G
  {"*...*.", "*...*.", "*****.", "*...*.", "*...*."}, //H
  {"*****.", "..*...", "..*...", "..*...", "*****."}, //I
  {"..***.", "...*..", "...*..", "*..*..", ".**..."}, //J
  {"*...*.", "*..*..", "***...", "*..*..", "*...*."}, //K
  {"*.....", "*.....", "*.....", "*.....", "*****."}, //L
  {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."}, //M
  {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."}, //N
  {".***..", "*...*.", "*...*.", "*...*.", ".***.."}, //O
  {"****..", "*...*.", "****..", "*.....", "*....."}, //P
  {".***..", "*...*.", "*...*.", "*..**.", ".****."}, //Q
  {"****..", "*...*.", "****..", "*..*..", "*...*."}, //R
  {".****.", "*.....", ".***..", "....*.", "****.."}, //S
  {"*****.", "*.*.*.", "..*...", "..*...", ".***.."}, //T
  {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."}, //U
  {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."}, //V
  {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."}, //W
  {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."}, //X
  {"*...*.", ".*.*..", "..*...", "..*...", "..*..."}, //Y
  {"*****.", "...*..", "..*...", ".*....", "*****."}, //Z
  {"......", "......", "......", "......", "......"}  //Blank
};

int i, j, k, l, m;
char page[MAX2][MAX2];

void flushPage(int print){
  for(i = 0; i < PAGEL; i++){
    for(j = 0; j < PAGEL; j++){
      //if(print && page[i][j] != '.' && page[i][j] != '*' && (page[i][j] > 'Z' || page[i][j] < 'A')) page[i][j] = '.';
      if(print) printf("%c", page[i][j]);
      page[i][j] = '.';
    }
    if(print) printf("\n");
  }
  if(print) printf("\n------------------------------------------------------------\n\n");
}

int main(void){
  char comm[MAX1], font[MAX1], str[MAX2];
  int r, c, end, bfont, ind;

  flushPage(0);
  while(scanf("%s ", comm) != EOF){
    if(!strcmp(comm, ".EOP")) {flushPage(1); continue;}	
    scanf("%s %d ", font, &r); 
    if(!strcmp(comm, ".P")) scanf("%d ", &c);
    fgets(str, MAX2, stdin);
    end = strlen(str)-2; str[end] = 0;
    bfont = strcmp(font, "C1");
    if(!strcmp(comm, ".P")){
      for(k = 1, i = r-1, j = c-1; k < end; j++, k++){
	if(str[k] == ' ' && !bfont) continue;
	if(!bfont && valido(i, j)) page[i][j] = str[k];
	else{
	  for(l = 0; l < 5; l++)
	    for(m = 0; m < 6; m++){
	      ind = str[k] == ' ' ? 26 : str[k] - 'A';
	      if(valido(i+l, j+m) && alfa[ind][l][m] != '.') page[i+l][j+m] = alfa[ind][l][m]; 
	    }
	  j += 5;
	}
      }
    }
    else if(!strcmp(comm, ".L")){
      for(k = 1, i = r-1, j = 0; k < end; j++, k++){
	if(str[k] == ' ' && !bfont) continue;
	if(!bfont && valido(i, j)) page[i][j] = str[k];
	else{
	  for(l = 0; l < 5; l++)
	    for(m = 0; m < 6; m++){
	      ind = str[k] == ' ' ? 26 : str[k] - 'A';
	      if(valido(i+l, j+m) && alfa[ind][l][m] != '.') page[i+l][j+m] = alfa[ind][l][m]; 
	    }
	  j += 5;
	}
      }
    }
    else if(!strcmp(comm, ".R")){
      for(k = end-1, i = r-1, j = PAGEL-1; k > 0; j--, k--){
	if(str[k] == ' ' && !bfont) continue;	
	if(!bfont && valido(i, j)) page[i][j] = str[k];
	else{
	  j -= 5;
	  for(l = 0; l < 5; l++)
	    for(m = 0; m < 6; m++){
	      ind = str[k] == ' ' ? 26 : str[k] - 'A';
	      if(valido(i+l, j+m) && alfa[ind][l][m] != '.') page[i+l][j+m] = alfa[ind][l][m]; 
	    }
	}
      }
    }
    else if(!strcmp(comm, ".C")){
      if(!bfont) j = (PAGEL/2) - (end-1)/2;
      else j = (PAGEL/2) - ((end-1)*6)/2;;
      for(k = 1, i = r-1; k < end; j++, k++){
	if(str[k] == ' ' && !bfont) continue;		
	if(!bfont && valido(i, j)) page[i][j] = str[k];
	else{
	  for(l = 0; l < 5; l++)
	    for(m = 0; m < 6; m++){
	      ind = str[k] == ' ' ? 26 : str[k] - 'A';
	      if(valido(i+l, j+m) && alfa[ind][l][m] != '.') page[i+l][j+m] = alfa[ind][l][m]; 
	    }
	  j += 5;
	}
      }
    }
  }
  return 0;
}
