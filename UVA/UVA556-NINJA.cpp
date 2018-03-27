#include <stdio.h>
#include <string.h>

#define MAX 1123
#define valido(i, j) (i >= 0 && i < n && j >= 0 && j < m && maze[i][j] != -1)

int movi[] = {0, -1, 0, 1};
int movj[] = {1, 0, -1, 0};

int main(void){
  int n, m, i, j, walls, first, dir, posi, posj, virou, maze[MAX][MAX], ans[5];
  char c;
  
  while(scanf("%d %d ", &n, &m), n){
    memset(ans, 0, sizeof(ans));
    for(walls = i = 0; i < n; i++){
      for(j = 0; j < m; j++){
	scanf("%c", &c);
	maze[i][j] = c - '0';
	if(maze[i][j] == 1) maze[i][j] = -1;
	walls += maze[i][j];
      }
      getchar();
    }
    maze[n-1][0] = 1;
    for(virou = 0, posi = n-1, posj = 1, dir = 0; posi != n-1 || posj != 0;){
      if((dir == 0 && valido(posi+1, posj)) || (dir == 1 && valido(posi, posj+1))||
	 (dir == 2 && valido(posi-1, posj)) || (dir == 3 && valido(posi, posj-1))){
	if(!virou) {dir = dir == 0 ? 3 : dir-1; virou = 1;}
      }
      if(!valido(posi+movi[dir], posj+movj[dir])){
	//printf("I: %d %d\n", posi+movi[dir], posj+movj[dir]);
	dir = dir == 3 ? 0 : dir+1; virou = 0;
      }
      else{
	maze[posi][posj]++;
	posi += movi[dir];
	posj += movj[dir];
	virou = 0;
      }
      //printf("%d %d,%d\n",dir, posi, posj);
    }
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++)
	if(maze[i][j] != -1) ans[maze[i][j]]++;
    for(first = 1, i = 0; i < 5; i++)
      printf("%3d", ans[i]);
    printf("\n");
  }
  return 0;
}
