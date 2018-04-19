#include <cstdio>
#include <cstring>

#define RIGHT 1
#define LEFT 2
#define TOP 3
#define BOTTOM 4
#define MAX 1123

typedef struct{
  int x;
  int y;
  int direction;
} robot;

typedef struct{
  int x;
  int y;
} coord;

robot r;
coord start;
int n, m;
int matrix[MAX][MAX], cmatrix[MAX][MAX];

void turnright(){
  if(r.direction == RIGHT) r.direction = BOTTOM;
  else if(r.direction == TOP) r.direction = RIGHT;
  else if(r.direction == LEFT) r.direction = TOP;
  else if(r.direction == BOTTOM) r.direction = LEFT;
}

void turnleft(){
  if(r.direction == RIGHT) r.direction = TOP;
  else if(r.direction == TOP) r.direction = LEFT;
  else if(r.direction == LEFT) r.direction = BOTTOM;
  else if(r.direction == BOTTOM) r.direction = RIGHT;
}

void turnback(){
  if(r.direction == RIGHT) r.direction = LEFT;
  else if(r.direction == TOP) r.direction = BOTTOM;
  else if(r.direction == LEFT) r.direction = RIGHT;
  else if(r.direction == BOTTOM) r.direction = TOP;
}

coord right(){
  coord c;
  if(r.direction == RIGHT){
    c.x = r.x;
    c.y = r.y+1;
    return c;
  }
  if(r.direction == TOP){
    c.x = r.x+1;
    c.y = r.y;
    return c;
  }
  if(r.direction == LEFT){
    c.x = r.x;
    c.y = r.y-1;
    return c;
  }
  else{
    c.x = r.x-1;
    c.y = r.y;
    return c;
  }
}

coord left(){
  coord c;
  if(r.direction == RIGHT){
    c.x = r.x;
    c.y = r.y-1;
    return c;
  }
  if(r.direction == TOP){
    c.x = r.x-1;
    c.y = r.y;
    return c;
  }
  if(r.direction == LEFT){
    c.x = r.x;
    c.y = r.y+1;
    return c;
  }
  else{
    c.x = r.x+1;
    c.y = r.y;
    return c;
  }
}

coord move(){
  coord c;
  if(r.direction == RIGHT){
    c.x = r.x+1;
    c.y = r.y;
    return c;
  }
  if(r.direction == TOP){
    c.x = r.x;
    c.y = r.y-1;
    return c;
  }
  if(r.direction == LEFT){
    c.x = r.x-1;
    c.y = r.y;
    return c;
  }
  else{
    c.x = r.x;
    c.y = r.y+1;
    return c;
  }
}

int valid(coord c){
  if(c.x >= 0 && c.x < m && c.y >= 0 && c.y < n)
    return 1;
  return 0;
}

int main(void){
  char c;
  int started;
  coord start;
  coord aux;
  int count0, count1, count2, count3, count4;
  while(scanf("%d %d", &n, &m), n != 0){
    count0 = count1 = count2 = count3 = count4 = 0;
    started = start.x = r.x = 0;
    r.direction = RIGHT;
    start.y = r.y = n-1;
    memset(cmatrix, 0, sizeof(cmatrix));
    for(int i = 0; i < n; i++){
      getchar();
      for(int j =0; j < m; j++){
	scanf("%c", &c);
	matrix[i][j] = c - '0';
      }
    }
    while((start.x != r.x || start.y != r.y) || !started){
      started = 1;
      coord cord = right();
      if(valid(right()) && matrix[cord.y][cord.x] == 0){
	turnright();
	cmatrix[r.y][r.x]++;
	aux = move();
	r.x = aux.x; r.y = aux.y;
      }
      else{
	cord = move();
	if(valid(move()) && matrix[cord.y][cord.x] == 0){
	  cmatrix[r.y][r.x]++;
	  aux = move();
	  r.x = aux.x; r.y = aux.y;
	}
	else{
	  cord = left();
	  if(valid(left()) && matrix[cord.y][cord.x] == 0){
	    turnleft();
	    cmatrix[r.y][r.x]++;
	    aux = move();
	    r.x = aux.x; r.y = aux.y;
	  }
	  else{
	    turnback();
	    cmatrix[r.y][r.x]++;
	    aux = move();
	    r.x = aux.x; r.y = aux.y;
	  }
	}
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	if(cmatrix[i][j] == 0 && matrix[i][j] != 1) count0++;
	else if(cmatrix[i][j] == 1 && matrix[i][j] != 1) count1++;
	  else if(cmatrix[i][j] == 2) count2++;
	  else if(cmatrix[i][j] == 3) count3++;
	  else if(cmatrix[i][j] == 4) count4++;
      }
    }
    printf("%3d%3d%3d%3d%3d\n", count0, count1, count2, count3, count4);
  }
  return 0;
}
