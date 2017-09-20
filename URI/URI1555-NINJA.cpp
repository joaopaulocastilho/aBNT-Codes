#include <stdio.h>

int frafael(int x,int y){ return (3*x)*(3*x)+y*y;}
int fbeto(int x,int y) { return 2*(x*x) + (5*y)*(5*y);}
int fcarlos(int x,int y){return -100*x + (y*y*y);}
	
int main(void){
	int N,x,y;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&x,&y);
		if ( frafael(x,y) > fbeto(x,y) && frafael(x,y) > fcarlos(x,y) ) printf("Rafael ganhou\n");
		else if (frafael(x,y) < fbeto(x,y) && fbeto(x,y) > fcarlos(x,y) ) printf("Beto ganhou\n");
		else printf("Carlos ganhou\n"); 
	}
	return 0;
}
