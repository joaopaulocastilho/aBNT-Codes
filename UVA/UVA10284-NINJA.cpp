#include <stdio.h>
#include <string.h>

#define MAX 112
#define valido(i, j) (i < 8 && i >= 0 && j < 8 && j >= 0)

int dirx[] = {1, 2,  2,  1, -1, -2, -2, -1};
int diry[] = {2, 1, -1, -2, -2, -1,  1,  2};
int ans;
char tab[15][15], attacked[15][15];

void checkHorVer(int i, int j, int single){
  int k;
  for(k = i+1; k < 8; k++){
    if(!attacked[k][j]){ attacked[k][j] = 1; ans--;}
    if(single || tab[k][j] != ' ') break;
  }
  for(k = i-1; k >= 0; k--){
    if(!attacked[k][j]){ attacked[k][j] = 1; ans--;}
    if(single || tab[k][j] != ' ') break;
  }
  for(k = j+1; k < 8; k++){
    if(!attacked[i][k]){ attacked[i][k] = 1; ans--;}
    if(single || tab[i][k] != ' ') break;
  }
  for(k = j-1; k >= 0; k--){
    if(!attacked[i][k]){ attacked[i][k] = 1; ans--;}
    if(single || tab[i][k] != ' ') break;
  }
}

void checkDiag(int i, int j, int single, char piece){
  int k, l;
  for(k = i+1, l = j+1; k < 8 && l < 8; k++, l++){
    if(piece == 'P') break;
    if(!attacked[k][l]){ attacked[k][l] = 1; ans--;}
    if(single || tab[k][l] != ' ') break;
  }
  for(k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--){
    if(piece == 'p') break;
    if(!attacked[k][l]){ attacked[k][l] = 1; ans--;}
    if(single || tab[k][l] != ' ') break;
  }
  for(k = i+1, l = j-1; k < 8 && l >= 0; k++, l--){
    if(piece == 'P') break;
    if(!attacked[k][l]){ attacked[k][l] = 1; ans--;}
    if(single || tab[k][l] != ' ') break;
  }
  for(k = i-1, l = j+1; k >= 0 && l < 8; k--, l++){
    if(piece == 'p') break;
    if(!attacked[k][l]){ attacked[k][l] = 1; ans--;}
    if(single || tab[k][l] != ' ') break;
  }
}

void checkKnight(int i, int j){
  int k, ni, nj;
  for(k = 0; k < 8; k++){
    ni = i + dirx[k]; nj = j + diry[k];
    if(valido(ni, nj) && !attacked[ni][nj]){
      attacked[ni][nj] = 1; ans--;
    }
  }
}

int main(void){
  int i, j, k, l, end, end2;
  char line[MAX];
  while(scanf("%s ", line) != EOF){
    memset(attacked, 0, sizeof(attacked));
    end = strlen(line);
    ans = 64;
    for(i = j = k = 0; k < end; k++){
      if(line[k] >= '1' && line[k] <= '9')
	for(end2 = line[k] - '0', l = 0; l < end2; l++) tab[i][j++] = ' ';
      else if(line[k] == '/'){ i++; j = 0; }
      else {tab[i][j] = line[k]; attacked[i][j++] = 1; ans--;}
    }
    for(i = 0; i < 8; i++)
      for(j = 0; j < 8; j++){
	if(tab[i][j] == 'q' || tab[i][j] == 'Q'){
	  checkHorVer(i, j, 0);
	  checkDiag(i, j, 0, tab[i][j]);
	}
	else if(tab[i][j] == 'p' || tab[i][j] == 'P') checkDiag(i, j, 1, tab[i][j]);
	else if(tab[i][j] == 'k' || tab[i][j] == 'K'){
	  checkHorVer(i, j, 1);
	  checkDiag(i, j, 1, tab[i][j]);
	}
	else if(tab[i][j] == 'r' || tab[i][j] == 'R') checkHorVer(i, j, 0);
	else if(tab[i][j] == 'b' || tab[i][j] == 'B') checkDiag(i, j, 0, tab[i][j]);
	else if(tab[i][j] == 'n' || tab[i][j] == 'N') checkKnight(i, j);
      }
    printf("%d\n", ans);
  } 
  return 0;
}
