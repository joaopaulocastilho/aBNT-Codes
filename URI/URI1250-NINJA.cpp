#include <stdio.h>
#define MAX 100
int main(void){
	int i,N,T,tiros[100],atingido;
	char pulos[MAX],c;
	scanf("%d",&N);
	while(N--){
		atingido = 0;
		scanf("%d",&T);
		for(i=0;i<T;i++) scanf("%d",&tiros[i]);
		for(i=0;i<T;){
			scanf("%c",&c);
			if(c != ' ' && c != '\n') pulos[i++] = c;
		}
		for(i=0;i<T;i++){
			if(pulos[i] == 'J' && tiros[i] > 2) atingido++;
			else if (pulos[i] == 'S' && tiros[i] <= 2) atingido++;
			
//printf("TIRO = %d | PULO = %c | atingido = %d\n",tiros[i],pulos[i],atingido);
		}
		printf("%d\n",atingido);
	}


	return 0;
}
