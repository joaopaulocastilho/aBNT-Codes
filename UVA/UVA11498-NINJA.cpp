#include <stdio.h>
int main(){
	int K,T,X,Y,x,y;
	scanf("%d",&T);
	while(T){
		K=T;
		scanf("%d %d",&X,&Y);
		while(K--){
			scanf("%d %d",&x,&y);
			if (x==X || y==Y) printf("divisa\n");
			else if(x>X && y>Y) printf("NE\n");
			else if(x<X && y>Y) printf("NO\n");
			else if(x<X && y<Y) printf("SO\n");
			else printf("SE\n");
		}
		
		scanf("%d",&T);
	}
	return 0;
}
