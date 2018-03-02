#include <cstdio>
#include <cstring>

#define MAX 8
//#define DEBUG

int bound(int i, int j){
  if(j >= 0 && j <= 7 && i >= 0 && i <= 7) return 1;
  return 0;
}

int main(void){
  int board[MAX][MAX], i, j, mboard[MAX][MAX], count;
  char c;
  memset(board, 0, sizeof(board));
  memset(mboard, 0, sizeof(mboard));
  i = j = 0;
  count = 0;
  while(scanf("%c", &c) != EOF){
    if(c == '\n'){
      for(i = 0; i < 8; i++){
	for(j = 0; j < 8; j++){
	  if(board[i][j] == 'K' || board[i][j] == 'k'){
	    if(bound(i-1, j)) mboard[i-1][j] = 1;
	    if(bound(i-1, j-1)) mboard[i-1][j-1] = 1;
	    if(bound(i-1, j+1)) mboard[i-1][j+1] = 1;
	    if(bound(i, j-1)) mboard[i][j-1] = 1;
	    if(bound(i, j+1)) mboard[i][j+1] = 1;
	    if(bound(i+1, j-1)) mboard[i+1][j-1] = 1;
	    if(bound(i+1, j)) mboard[i+1][j] = 1;
	    if(bound(i+1, j+1)) mboard[i+1][j+1] = 1;
	    mboard[i][j] = 1;
	    }
	  else if(board[i][j] == 'q' || board[i][j] == 'Q'){
	    mboard[i][j] = 1;
	    for(int k = i+1, l = j+1; k < 8 && l < 8; k++, l++){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	    for(int k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	    for(int k = i+1, l = j-1; k < 8 && l >= 0; k++, l--){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	    for(int k = i-1, l = j+1; k >= 0 && l < 8; k--, l++){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	    for(int k = i+1; k < 8; k++){ mboard[k][j] = 1; if(board[k][j] != 0) break; }
	    for(int k = i-1; k >= 0; k--){ mboard[k][j] = 1; if(board[k][j] != 0) break; }
	    for(int k = j+1; k < 8; k++){ mboard[i][k] = 1; if(board[i][k] != 0) break; }
	    for(int k = j-1; k >= 0; k--){ mboard[i][k] = 1; if(board[i][k] != 0) break; }
	    }
	  else if(board[i][j] == 'b' || board[i][j] == 'B'){
	    mboard[i][j] = 1;
	    for(int k = i+1, l = j+1; k < 8 && l < 8; k++, l++){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	    for(int k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	    for(int k = i+1, l = j-1; k < 8 && l >= 0; k++, l--){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	    for(int k = i-1, l = j+1; k >= 0 && l < 8; k--, l++){ mboard[k][l] = 1; if(board[k][l] != 0) break; }
	  }
	  else if(board[i][j] == 'r' || board[i][j] == 'R'){
	    mboard[i][j] = 1;
	    for(int k = i+1; k < 8; k++){ mboard[k][j] = 1; if(board[k][j] != 0) break; }
	    for(int k = i-1; k >= 0; k--){ mboard[k][j] = 1; if(board[k][j] != 0) break; }
	    for(int k = j+1; k < 8; k++){ mboard[i][k] = 1; if(board[i][k] != 0) break; }
	    for(int k = j-1; k >= 0; k--){ mboard[i][k] = 1; if(board[i][k] != 0) break; }
	    }
	  else if(board[i][j] == 'p'){
	    mboard[i][j] = 1;
	    if(bound(i+1, j-1)) mboard[i+1][j-1] = 1;
	    if(bound(i+1, j+1)) mboard[i+1][j+1] = 1;
	    }
	  else if(board[i][j] == 'P'){
	    mboard[i][j] = 1;
	    if(bound(i-1, j-1)) mboard[i-1][j-1] = 1;
	    if(bound(i-1, j+1)) mboard[i-1][j+1] = 1;
	  }
	  else if(board[i][j] == 'n' || board[i][j] == 'N'){
	    mboard[i][j] = 1;
	    if(bound(i-1, j-2)) mboard[i-1][j-2] = 1;
	    if(bound(i-1, j+2)) mboard[i-1][j+2] = 1;
	    if(bound(i+1, j-2)) mboard[i+1][j-2] = 1;
	    if(bound(i+1, j+2)) mboard[i+1][j+2] = 1;
	    if(bound(i+2, j-1)) mboard[i+2][j-1] = 1;
	    if(bound(i+2, j+1)) mboard[i+2][j+1] = 1;
	    if(bound(i-2, j-1)) mboard[i-2][j-1] = 1;
	    if(bound(i-2, j+1)) mboard[i-2][j+1] = 1;
	    }
	}
      }
      for(i = 0; i < 8; i++)
	for(j = 0; j < 8; j++)
	  if(mboard[i][j] == 0) count++;
      printf("%d\n", count);
#ifdef DEBUG
      for(i = 0; i < 8; i++){
	for(j = 0; j < 8; j++){
	  if(j != 0) printf(" ");
	  printf("%c", board[i][j] == 0 ? '0' : board[i][j] == '1' ? '1' : board[i][j]);
	}
	printf("\n");
      }
      printf("\n");
      for(i = 0; i < 8; i++){
	for(j = 0; j < 8; j++){
	  if(j != 0) printf(" ");
	  printf("%d", mboard[i][j]);
	}
	printf("\n");
      }
      printf("\n");
#endif
      memset(board, 0, sizeof(board));
      memset(mboard, 0, sizeof(board));
      i = j = 0;
      count = 0;
    }
    else{
      if(c == '/'){ i++; j = 0; continue; }
      if(c >= '0' && c <= '8'){ j += c - '0'; }
      else{ board[i][j++] = c;}
    }
  }
  return 0;
}
