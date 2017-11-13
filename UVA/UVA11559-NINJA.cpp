#include <stdio.h>
int main(){
	int N,B,H,W,P,a,menpreco;
	while(scanf("%d %d %d %d",&N,&B,&H,&W) != EOF){
		menpreco=-1;
		while(H--){
			scanf("%d",&P);
			for(int i=0 ; i<W;i++){
				scanf("%d",&a);
				if ( (a>=N && P*N < menpreco) ||menpreco== -1 ) menpreco = P*N;
			}
		}
	if (menpreco <= B) printf("%d\n",menpreco);
	else printf("stay home\n");	
	}
	
	
	return 0;
}
