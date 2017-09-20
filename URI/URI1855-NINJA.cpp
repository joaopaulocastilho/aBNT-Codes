#include <stdio.h>

typedef struct{
	int i,j;
}coord;

typedef struct{
	char c;
	int vis;
}lugar;

int main(void){
	int i,j,x,y,acabou = 0;
	char c;
	coord pos,dir;
	lugar mapa[150][150];
	scanf("%d\n",&x);
	scanf("%d\n",&y);
	for(i=0;i<y;i++)
		for(j=0;j<x;){
			scanf("%c",&c);
			if( c != '\n' ){
				mapa[i][j].c = c;
				mapa[i][j].vis = 0;
				j++;
			}
		}
	pos.i = pos.j = dir.i = dir.j = 0;
	
	while(!acabou){
		if( mapa[pos.i][pos.j].c == '*' ){
			printf("*\n");
			acabou = 1;
		}
		else if(mapa[pos.i][pos.j].vis > 4 || pos.i >= y || pos.j >= x || pos.i < 0 || pos.j<0){
			printf("!\n");
			acabou = 1;
		}
		switch (mapa[pos.i][pos.j].c){
			case '>' : dir.i = 0; dir.j= 1; break;
			case '<' : dir.i = 0; dir.j= -1; break;
			case '^' : dir.i = -1; dir.j= 0; break;
			case 'v' : dir.i = 1; dir.j= 0; break;
		}
		mapa[pos.i][pos.j].vis++;
		pos.i += dir.i;
		pos.j += dir.j;
	}
	return 0;
}
